#include <iostream>
#include <memory>
#include <vector>

int row = 2;
int col = 4;

/**
 * @brief 二维转一维
 * @return int 一维索引
 */
int f(int i, int j)
{
    return i * col + j;
}

/**
 * @brief 一维转二维
 * @return std::tuple<int, int> 二维索引
 */
std::tuple<int, int> F(int I)
{
    return std::make_tuple<int, int>(I / col, I % col);
}

/**
 * @brief 转置矩阵二维转一维
 * @return int 一维索引
 */
int g(int i, int j)
{
    return i * row + j;
}

/**
 * @brief 转置矩阵一维转二维
 * @return std::tuple<int, int> 二维索引
 */
std::tuple<int, int> G(int I)
{
    return std::make_tuple<int, int>(I / row, I % row);
}

int main()
{
    std::vector<int> n, m;
    n.resize(row * col);
    m.resize(row * col);
    int i, j, temp = 0;
    printf("原始矩阵:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            n[f(i, j)] = ++temp;
            printf("%d\t", n[f(i, j)]); /*输出原始矩阵*/
        }
        printf("\n");
    }
    temp = 0;

    i = 0;
    int work = 0;
    int cur = 0;
    int next = 0;
    std::tuple<int, int> res;
    while (i < row)
    {
        // j = i + 1;
        res = F(work + 1);
        i = std::get<0>(res);
        j = std::get<1>(res);
        int &guard = n[f(i, j)];
        int i_ = i, j_ = j;
        while (j < col)
        {
            cur = f(i, j);
            next = g(j, i);
            std::cout << "swap(" << guard << "," << n[next] << ")" << std::endl;

            if (next <= cur)
            {
                std::cout << "done" << std::endl;
                break;
            }
            std::swap(guard, n[next]);

            if (next - cur == 1)
            {
                work = next;
            }
            res = F(next);
            i = std::get<0>(res);
            j = std::get<1>(res);
            if (i_ == j and j_ == i)
            {
                std::cout << "complete once" << std::endl;
                break;
            }
        }
    }

    printf("转置矩阵:\n");
    std::swap(row, col);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d  ", n[f(i, j)]); /*输出原始矩阵的转置矩阵*/
        printf("\n");
    }
    return 0;
}
