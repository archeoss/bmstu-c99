int *fill_fibonacci(int *array, int n)
{
    int num_a = 0, num_b = 1;

    for (int i = 0; i < n; i++)
    {
        array[i] = num_a;
        int num_c = num_a + num_b;
        num_a = num_b;
        num_b = num_c;
    }

    return array;
}

int *fill_unique(int *array_src, int *array_dst, int src_len, int *dst_len)
{
    *dst_len = 0;
    for (int i = 0; i < src_len; i++)
    {
        int flag = 1;
        for (int j = 0; j < *dst_len && flag == 1; j++)
            if (array_dst[j] == array_src[i])
                flag = 0;
        if (flag)
            array_dst[(*dst_len)++] = array_src[i];
    }

    return array_dst;
}