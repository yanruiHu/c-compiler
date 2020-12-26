int main() {
    int a, b = 1;
    int c = 3;
    a = b + (10 / 2) ^ 3; 
    if (a != 0) {
        while (a < 10 && b < 10) {
            a = a * b * c;
            b = b % 2;
        }
        for (int i = 0; i < 1; i=1+i) { 
            i = b + a;
        }
    }
    return a;
}
