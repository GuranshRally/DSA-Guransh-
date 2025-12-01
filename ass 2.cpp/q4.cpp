#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int ch;
    char s1[100], s2[100], s[100], out[100];
    while (true) {
        cout << "1 Concatenate\n2 Reverse\n3 Remove Vowels\n4 Sort Strings\n5 Upper to Lower\n6 Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> s1 >> s2;
            strcat(s1, s2);
            cout << s1 << endl;
        }

        else if (ch == 2) {
            cin >> s;
            int n = strlen(s);
            for (int i = 0; i < n / 2; i++) {
                char t = s[i];
                s[i] = s[n - i - 1];
                s[n - i - 1] = t;
            }
            cout << s << endl;
        }

        else if (ch == 3) {
            cin.ignore();
            cin.getline(s, 100);
            int k = 0;
            for (int i = 0; s[i] != '\0'; i++) {
                char c = s[i];
                if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
                    c!='A' && c!='E' && c!='I' && c!='O' && c!='U') {
                    out[k++] = c;
                }
            }
            out[k] = '\0';
            cout << out << endl;
        }

        else if (ch == 4) {
            int n;
            cin >> n;
            char a[20][100];
            for (int i = 0; i < n; i++) cin >> a[i];
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (strcmp(a[i], a[j]) > 0) {
                        char t[100];
                        strcpy(t, a[i]);
                        strcpy(a[i], a[j]);
                        strcpy(a[j], t);
                    }
                }
            }
            for (int i = 0; i < n; i++) cout << a[i] << endl;
        }

        else if (ch == 5) {
            char c;
            cin >> c;
            if (c >= 'A' && c <= 'Z') c = c + 32;
            cout << c << endl;
        }

        else if (ch == 6) break;
    }
}