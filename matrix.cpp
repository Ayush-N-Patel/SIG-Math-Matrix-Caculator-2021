#include <vector>
#include <assert.h>
#include "matrix.h"
//TODO

// multiply each element of the row by the scalar value
void matrix::multiScal(int scalar, int row) {

   for(int i=0;i<col;i++) {
     matrice[row][col] = matrice[row][col]*scalar; 
   }

}


void matrix::reduceCol(const int& col)
{
    //col muse be in bounds, and matrice must not be empty
    assert(col >= 0)
    assert(col < matrice.size())
    assert(!matrice.empty())


    //getting the pivot point from input Col
    const auto pivotNum = matrice.at(0).at(col);


    //TODO:iterate through the matrice
    //divide only the input col with the pivotNum
    //transforming the pivot location to 1
    for(auto row = 0; row < matrice.size(); ++row)
    {
        //using at() instead of operator[] to avoid undefined behavior
        //TODO: avoid case that 0 / num
        try{

            (matrice.at(row).at(col) != 0 ) ? matrice.at(row).at(col) /= pivotNum;
        }
        catch(const auto& e)
        {
            //access out of bound
            throw logic_error("access index location is out of bound");
        }
    }


    //since the pivot number always start at index row 0 and fixed col, turns the remaining row in the col to 0
    for(auto row = 1; row < matrice.size(); ++row)
    {
        matrice.at(row).at(col) = 0;
    }


}//Chris- reduce column