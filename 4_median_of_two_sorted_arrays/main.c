#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    unsigned int num = nums1Size + nums2Size;
    int *out;
    int i = 0, j = 0;
    int i_num = 0, j_num = 0;
    double result;
    
    if (num == 0) {
        return 0;
    }
    
    if (nums2Size == 0) {
        out = nums1;
    } else {
        if (nums1Size == 0) {
            out = nums2;
        } else {
            out = malloc(sizeof(int) * num);
        }
    }

    for (i = 0; i < nums1Size; i++) {
        for (; j < nums2Size; j++) {
            if (nums2[j] > nums1[i]) {
                out[i+j] = nums1[i];
                i_num++;
                break;
            } else {
                out[i+j] = nums2[j];
                j_num++;
            }
        }
    }

    for (; i_num < nums1Size; i_num++) {
        out[nums2Size + i_num] = nums1[i_num];
    }

    for (; j_num < nums2Size; j_num++) {
        out[nums1Size + j_num] = nums2[j_num];
    }

    printf("i = %d\n", i);
    printf("j = %d\n", j);

    for (int i = 0; i < num; i++) {
        printf("out[%d] = %d\n", i, out[i]);
    }

    if ((num % 2) == 0) {
        result = (out[(num>>1)] + out[(num>>1)-1]) / 2.0f;
    } else {
        result = out[(num>>1)];
    }

    return result;
}

int main(void)
{
    int a[1] = {10001};
    int b[1] = {10000};
    printf("%lf\n", findMedianSortedArrays(a, (sizeof(b)/sizeof(int)), b, (sizeof(b)/sizeof(int))));
}