void swap(int* a1, int* b) {
    int t = *a1;
    *a1 = *b;
    *b = t;
}

int main()
{
    int a = 2;
    int b = 3;
    int* pa = &a;
    int* pb = &b;
    swap(pa, pb);
}
