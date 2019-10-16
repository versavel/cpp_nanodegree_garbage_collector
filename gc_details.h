// The PtrDetails class defines an element that is stored
// in the garbage collection information list

template <class T>
class PtrDetails
{
  public:
    
    // reference count
    unsigned refcount; 
    
    // pointer to allocated memory
    T *memPtr;
    
    // true if pointing to an array
    bool isArray;

    // size of the array
    unsigned arraySize; 

    // Constructor
    //   m_ptr points to the allocated memory
    //   size specifies size of the arra.
    PtrDetails(T *m_ptr, unsigned size = 0)
    {
        refcount = 1;
        memPtr = m_ptr;
        if (size != 0) isArray = true;
        else isArray = false;

        arraySize = size;
    }
};

// Overloading operator == allows two class objects to be compared
// This is needed by the STL list class

template <class T>
bool operator == (const PtrDetails<T> &ob1,
                  const PtrDetails<T> &ob2) 
{
    if ((ob1.memPtr == ob2.memPtr)
        && (ob1.isArray == ob2.isArray) 
        && (ob1.arraySize == ob2.arraySize))
        return true;
    else return false;
}
