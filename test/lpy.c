int main()
{
    int a = 1,b=1;
    int c = 2;
    int i ;
    
    for (i=0; i < 10; i = i + 1)
    {
        if (a < 5)
            a = a + 1;
        else if (a >= 5)
        {
            a = a + 2;
        }
    }
    print_int(i);
    while (a < 40)
    {
        a = a + 1;
    }
    print_int(a);
    return 0;
}