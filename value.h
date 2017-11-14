#ifndef VALUE_H
#define VALUE_H

#include <ios>
#include <ostream>
#include <cmath>

#include <variant/include/eggs/variant.hpp>

const static std::string dummy {};

class Value
{
    using variant_t = eggs::variant <bool, int, double, std::string>;

public:
    enum class Type
    {
        Invalid = -1,
        Boolean = 0,
        Integer,
        Real,
        String,
    };

    using real = double;

    const variant_t& value () const { return m_value; }

    const std::string& toString () const
    {
        if (type() != Type::String)
            return dummy;
        return eggs::variants::get<std::string> (m_value);
    }

    int toInteger () const
    {
        switch (type ())
        {
        case Type::Integer:
            return eggs::variants::get<int> (m_value);
            break;
        case Type::Boolean:
            return int (eggs::variants::get<bool> (m_value));
            break;
        case Type::Real:
            return int (eggs::variants::get<real> (m_value));
            break;
        default:
            return 0;
            break;
        }
    }

    bool toBoolean () const
    {
        switch (type ())
        {
        case Type::Boolean:
            return eggs::variants::get<bool> (m_value);
            break;
        case Type::Integer:
            return int (eggs::variants::get<bool> (m_value));
            break;
        case Type::Real:
            return real (eggs::variants::get<bool> (m_value));
            break;
        default:
            return false;
            break;
        }
    }

    real toReal () const
    {
        switch (type ())
        {
        case Type::Real:
            return eggs::variants::get<real> (m_value);
            break;
        case Type::Integer:
            return int (eggs::variants::get<real> (m_value));
            break;
        case Type::Boolean:
            return bool (eggs::variants::get<real> (m_value));
            break;
        default:
            return false;
            break;
        }
    }

    Type type () const
    {
        return Type (m_value.which ());
    }

    Value () = default;
    Value (const Value&) = default;
    Value (Value&&) = default;

    Value& operator= (const Value&) = default;
    Value& operator= (Value&&) = default;

    template<typename T>
    Value (const T& t)
    {
        m_value = t;
    }

    template<typename T>
    Value (T&& t)
    {
        m_value = t;
    }

    /*
    template<typename T>
    Value& operator= (T&& t)
    {
        value = t;
        return *this;
    }
    */

    template<typename T>
    Value& operator= (const T& t)
    {
        m_value = t;
        return *this;
    }



private:
    variant_t m_value;
};

std::ostream& operator<< (std::ostream& out, Value::Type type)
{
    switch (type)
    {
    case Value::Type::Boolean:
        out << "Type::Boolean";
        break;
    case Value::Type::Integer:
        out << "Type::Integer";
        break;
    case Value::Type::Real:
        out << "Type::Real";
        break;
    case Value::Type::String:
        out << "Type::String";
        break;
    default:
        out << "Type::Invalid";
        break;
    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const Value& value)
{
    Value::Type type = value.type();
    switch (type)
    {
    case Value::Type::Boolean:
        out << type << " " << std::boolalpha << value.toBoolean() << std::noboolalpha;
        break;
    case Value::Type::Integer:
        out << type << " "<< value.toInteger();
        break;
    case Value::Type::Real:
        out << type << " " << value.toReal();
        break;
    case Value::Type::String:
        out << type << " "<< value.toString();
        break;
    default:
        out << type << " " << "(Invalid)";
        break;
    }
    return out;
}

#endif // VALUE_H
