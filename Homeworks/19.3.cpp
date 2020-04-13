/*  Reid Harry
    4/13/2020
    Another common technique to avoid having to pass a separate argument for the array's size is to make the first element of the array 
    hold its size. Of course this only works for numeric arrays, but arrays of numbers are the most common kind.

    Write the "copy_stock_prices" like before, but the first element contains the number of prices in the array, only copy those. 
*/

void copy_stock_prices(double source[], double dest[]){
    for(size_t i = 0; i < static_cast<size_t>(source[0]+1); i++){
        dest[i] = source[i];
    }
}