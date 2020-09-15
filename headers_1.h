#ifndef HEADERS_1_H_INCLUDED
#define HEADERS_1_H_INCLUDED
namespace Lab1{
    struct Line{
        int n;
        int *mas;
    };
    template <class T>
    int getNum(T &a){
    std::cin >> a;
    if(!std::cin.good())
        return -1;
    return 1;
    }
    int is_even(int );
    Line* process(int i, Line *&lines);
    Line* sort(Line *&lines, int m);
    int count_real(Line *&mas);
    Line* input(int &);
    void output(const char *msg, Line mas[], int m);
    Line *erase(Line *&mas, int m);


}


#endif // HEADERS_1_H_INCLUDED
