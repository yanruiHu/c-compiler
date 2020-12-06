int i = 1;
int a, b;

int print_int(int i) {
    int a = 1, b = 2;
}

int main() {
    int a = 1, b = 2;
    int c = 2;
    int i = 0;
    for (i = 0; i < 10; i = i + 1) {
        int c;
        if (a < 5) a = a + 1;
        else if (a >= 5) {
            int b = 2;
            a = a + 2;
        }
    }
    print_int(i);
    while(a < 40) {
        int z;
        a = a + 1;
    }
    print_int(a);
    return 0;
}