#include <iostream>
#include "MultDim.h"
#include <vector>
using namespace std;

int main() {
    int initialValue = 0x21;
    size_t totalBytesNeeded1 = CreateArrayAtMemory<short>(nullptr, 2, 4);
    vector<char> memoryBlock1(totalBytesNeeded1);
    char** pointerArray1 = (char**)memoryBlock1.data();
    CreateArrayAtMemory(pointerArray1, 2, 4);
    for (int row = 0; row < 2; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            
                pointerArray1[row][column] = initialValue++;
        }
    }
    // Dump
    for (int row = 0; row < 2; row++)
    {
        for (int column = 0; column < 4; column++)
        {
                std::cout << (int)pointerArray1[row][column] << " ";
        }
    }
    std::cout << std::endl << totalBytesNeeded1 << " bytes used " << std::endl;
    std::cout << std::endl;
    
    int init_value0 = 0x21;
    size_t arr1_size = CreateArrayAtMemory(nullptr, 2);
    vector <char> memory_block1(arr1_size);
    char* data_arrr = (char*)memory_block1.data();
    CreateArrayAtMemory(data_arrr, 2);
    for (int i1 = 0; i1 < 2; i1++)
    {
        data_arrr[i1] = init_value0++;
    }
    for (int i1 = 0; i1 < 2; i1++)
    {
        std::cout << (int)data_arrr[i1] << " ";
    }
    std::cout << std::endl << arr1_size << " bytes used " << std::endl;
    int init_value = 0x21;
    size_t arr2_size = CreateArrayAtMemory<short>(nullptr, 2, 3);
    vector<char> memory_block(arr2_size);
    short** data_arr = (short**)memory_block.data();
    CreateArrayAtMemory<short>(data_arr, 2, 3);
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            data_arr[row][col] = init_value++;
        }
    }
    // Dump
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << (int)data_arr[row][col] << " ";
        }
    }
    std::cout << std::endl << arr2_size << " bytes used " << std::endl;
    std::cout << std::endl;

    int starting_value = 0x21;
    size_t array5Size = CreateArrayAtMemory<int>(nullptr, 2, 3, 4, 5, 6);
    vector<char> array5Memory(array5Size);
    int***** array5 = (int*****)array5Memory.data();
    CreateArrayAtMemory<int>(array5, 2, 3, 4, 5, 6);

    for (int i1 = 0; i1 < 2; i1++) {
        for (int i2 = 0; i2 < 3; i2++) {
            for (int i3 = 0; i3 < 4; i3++) {
                for (int i4 = 0; i4 < 5; i4++) {
                    for (int i5 = 0; i5 < 6; i5++) {
                        array5[i1][i2][i3][i4][i5] = starting_value++;
                    }
                }
            }
        }
    }

    // Dump
    for (int i1 = 0; i1 < 2; i1++) {
        for (int i2 = 0; i2 < 3; i2++) {
            for (int i3 = 0; i3 < 4; i3++) {
                for (int i4 = 0; i4 < 5; i4++) {
                    for (int i5 = 0; i5 < 6; i5++) {
                        std::cout << (int)array5[i1][i2][i3][i4][i5] << " ";
                    }
                }
            }
        }
    }
    std::cout << std::endl << array5Size << " bytes used " << std::endl;
    std::cout << std::endl;


    //int init_value = 0x21;
    //auto arr = CreateMultiDimensionalArray<char>(2, 3, 4, 5, 6);

    //for (size_t i1 = 0; i1 < arr.size(); ++i1) {
    //    for (size_t i2 = 0; i2 < arr[i1].size(); ++i2) {
    //        for (size_t i3 = 0; i3 < arr[i1][i2].size(); ++i3) {
    //            for (size_t i4 = 0; i4 < arr[i1][i2][i3].size(); ++i4) {
    //                for (size_t i5 = 0; i5 < arr[i1][i2][i3][i4].size(); ++i5) {
    //                    arr[i1][i2][i3][i4][i5] = init_value++;
    //                }
    //            }
    //        }
    //    }
    //}

    //// Виведення значень елементів масиву на екран
    //for (const auto& level1 : arr) {
    //    for (const auto& level2 : level1) {
    //        for (const auto& level3 : level2) {
    //            for (const auto& level4 : level3) {
    //                for (const auto& value : level4) {
    //                    std::cout << static_cast<int>(value) << " ";
    //                }
    //            }
    //        }
    //    }
    //}

   

    return 0;
}