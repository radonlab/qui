#ifndef QUI_SRC_QUI_TYPES_H_
#define QUI_SRC_QUI_TYPES_H_

// A macro to disallow the copy constructor
#define DISALLOW_COPY(TypeName) \
  TypeName(const TypeName&) = delete

// A macro to disallow the assign functions
#define DISALLOW_ASSIGN(TypeName) \
  TypeName& operator=(const TypeName&) = delete

// A macro to disallow the copy constructor and assign functions
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  DISALLOW_COPY(TypeName);                 \
  DISALLOW_ASSIGN(TypeName)

// A macro to disallow all the implicit constructors, namely the
// default constructor, copy constructor and assign functions
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
  TypeName() = delete;                           \
  DISALLOW_COPY_AND_ASSIGN(TypeName)

#endif  // QUI_SRC_QUI_TYPES_H_
