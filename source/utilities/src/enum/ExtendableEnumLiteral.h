#ifndef EXTENDABLEENUMLITERAL_H
#define EXTENDABLEENUMLITERAL_H

#include <map>
#include <stdint.h>

class ExtendableEnum;

////////////////////////////////////////////////////////////////////////////////////
/// \details This class provides the ability to mesh multiple enumerations
/// together into a single access point
////////////////////////////////////////////////////////////////////////////////////
class ExtendableEnumLiteral
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \details Constructor as unassigned
    /// \param [in] enumType - Pointer to the Extenable Enumeration Type that
    /// this object is associated with
    ////////////////////////////////////////////////////////////////////////////////
    ExtendableEnumLiteral(const ExtendableEnum& enumType);

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Constructor as assigned
    /// \param [in] enumType - Pointer to the Extenable Enumeration Type that
    /// this object is associated with
    /// \param [in] literal - The enumeration literal to assign to the object
    ////////////////////////////////////////////////////////////////////////////////
    ExtendableEnumLiteral(const ExtendableEnum& enumType, int64_t literal);

    ////////////////////////////////////////////////////////////////////////////////
    /// \details Destructor
    ////////////////////////////////////////////////////////////////////////////////
    ~ExtendableEnumLiteral();

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Assigns literal
    /// \details This function takes an enumeration literal whose type is
    /// specified by the template parameter. It then casts the literal to an
    /// 64-bit integer and sets the value for this object to it.
    /// \param [in] literal - The enumeration literal to assign to the
    /// object
    ////////////////////////////////////////////////////////////////////////////////
    // template <typename T>
    // void setLiteral(const T literal);

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Compares a literal to this object
    /// \details This function takes an enumeration literal
    /// whose type is specified by the template parameter. It then casts the
    /// literal to an 64-bit integer and checks to see if the casted value
    /// is
    /// equal to this object
    /// \param [in] literal - The enumeration literal to compare aginst
    /// \return bool - TRUE if literal is equal to this object, FALSE if
    /// either
    /// the literal is not equal, or a value was never assigned
    ////////////////////////////////////////////////////////////////////////////////
    // template <typename T>
    // bool isEqual(const T literal);

    ////////////////////////////////////////////////////////////////////////////////
    /// \brief Less than operator
    /// \details This function specifies the less than operator to use in a
    /// std::map
    /// \param [in] rhs - The ExtendableEnumLiteral to compare against
    /// \return bool - TRUE if this instance is less than the rhs, FALSE
    /// otherwise
    ////////////////////////////////////////////////////////////////////////////////
    bool operator<(const ExtendableEnumLiteral& rhs) const;

private:
    // The Extendable Enumerated Type that this variable is associated with
    const ExtendableEnum& mp_enumType;

    // The integer equivalent value of the enumeration literal that was
    // assigned
    int64_t m_literal;
};
#endif // EXTENDABLEENUMLITERAL_H

#ifndef EXTENDABLEENUMLITERAL_C
#define EXTENDABLEENUMLITERAL_C
#include "ExtendableEnumLiteral.cpp"
#endif