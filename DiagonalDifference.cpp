int diagonalDifference(vector<vector<int>> arr)
{
    size_t arr_size = arr.size() - 1;
    
    int left_diagonal_sum = 0;
    int right_diagonal_sum = 0;
    
    for (size_t i = 0; i <= arr_size; ++i)
    {
        left_diagonal_sum += arr[i][i];
        right_diagonal_sum += arr[i][arr_size-i];
    }
    
    return std::abs(left_diagonal_sum - right_diagonal_sum);
}
