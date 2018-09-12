/* 
 STL: Standard Template Library
 */

#include <iostream>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <string>

// std::array - fixed size sequence containers 
//              in a strict linear order
// Does not keep any data other than the elements
// it contains, not even its size(fixed on compile time).
// As efficient as ordinary array type_t arr[]

// PROPERTIES
/*
 Does not manage the allocation of its elements
 through an allocator. They are an aggregate type,
 encapsulating a fixed-size array of elements, thus,
  they cannot expand or cotract dynamically.
 
 Cna be treated as a tuple
 
 */

// Iterators: Obejct for container traversal
// three implementaitons:
//
//  1) Iterators from nested containers
//
//  2) Iterators from pointers
//
//  3) Iterators from Iterators


#define N 4








int main() {
    //std::string hw("echo Hello World!");
    //std::system(hw.c_str());
  
    int a = 10;
    int b = 12;
    int *c = &b;
    //std::cout << b << std::endl;
    *c = 1000;
    //std::cout << b << std::endl;
    //std::cout << c << std::endl;
    
    // pointer to an array
    int arr[5] = {1,2,3,4,5};
    int arr2[5] = {2,4,6,8,10};
    int *aptr = &arr2[2];
    //std::cout << *aptr << " " <<*(aptr+1) << std::endl;
    
    int *a2ptr = arr2;
    //std::cout << a2ptr << " "<< *a2ptr << " " <<*(a2ptr+1) << std::endl;
    
    
    // pointer to pointer
    int x = 1;
    int *y = &x;
    int **z = &y;   // z is a pointer to a pointer
    int ***u = &z;   // u is a pointer to a pointer to pointer
    
    //std::cout << "y = " << y << " " << "*y = "  << *y << std::endl;
    //std::cout << "z = " << z << " " <<"*z = " << *z 
    //        << " " << "**z = " << **z << std::endl;
    
    //std::cout <<"u = " << u << " " << "*u = " << *u << " "
    //            << "**u = " << **u << " " << "***u = " << ***u << std::endl;
    
    int aa = 10;
    const int *p1 = &aa;    // p1 is a pointer that points to a const int aa
                            // cannot use p1 to modify aa
    
    int aaa = 11;
    int *const p2 = &aaa;   // p2 is immutable pointer that points to an int
                            // we can modify aaa through p2
                            // memory address must stay unchanged
    
    
    // user defined types: structures, enumerations
    struct my_struct{
        
    };
    
    // days of the week
    enum weekdays {mon=1, tues=2, wed=3, thurs=4, fri=5, sat=6, sun=0};
    
    // employee structure
    struct Employee {
        std::string name;   // name
        std::string dob;    // date of birth
        std::string id;     // company id
        float wage;         // salary
    };
    
    Employee will;
    Employee *emptr = &will;
    emptr->name = "William Murphy";
    emptr->dob = "05/31/1987";
    emptr->id = "1007989";
    emptr->wage = 125000;
    //std::cout << will.name << std::endl;
    //std::cout << will.dob << std::endl;
    //std::cout << will.id << std::endl;
    //std::cout << will.wage << std::endl;
    
    
    // memory allocation: c++ 
    {
        // use the new keyword to dynamically allocate new memory spaces
        int *dptr = new int;
        *dptr = 4;
        //std::cout << "*dptr = " << *dptr << std::endl;
        // deallocate with delete
        delete dptr;
    }
    
    std::vector<std::vector<int>> A ={{1,10,0}, {1,7,1}};
    std::vector<std::vector<int>> B = {{1,0},{1,2}, {1,1}};
    int C[2][2];
    
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            int value = 0;
            for(int k=0; k<3; k++){
                value += A[i][k]*B[k][j];
            }
            C[i][j] = value;
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            //std::cout << C[i][j] << std::endl;
        }
    }
    
    std::vector<std::vector<int>> mat = {{1,0,2,},
                                         {3,0,0},
                                         {2,1,4,}};
    
    static_assert(4 <= sizeof(int), "sizeof(int) too small");
    
    
    
    
    
    
    
    
    return 0;
} 
