#include <iostream>
#include "headers_1.h"

namespace Lab1{
    Line *input(int &rm){
        const char *pr="";
        Line *lines=nullptr;
        int m;

        do{
            std::cout << pr << std::endl;
            std::cout << "Enter number of lines: -->";
            pr="You are wrong; repeat please!";
            if(getNum(m) < 0)
                    return nullptr;
        }while(m<1);

        try{
            lines=new Line[m];
        }
        catch(std::bad_alloc &ba){
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }
        for(int i=0; i<m; i++){

            pr="";
            do{
                std::cout << pr << std::endl;
                std::cout << "Enter number of items in line #" << (i+1) << " --> ";
                pr="You are wrong; repeat please!";
                if(getNum(lines[i].n) < 0){
                    erase(lines, i);
                    return nullptr;
                }
                if(lines[i].n > MAX){
                    std::cout<< "You want too many elements" << std::endl;
                    lines[i].n=0;
                }

            }while(lines[i].n < 1);

           /* try{
                lines[i].mas=new int*[lines[i].n];
            }
            catch(std::bad_alloc &ba){
                 std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
                 erase(lines, i);
                 return nullptr;
            } */

           // std::cout << "Enter items for matrix line #" << (i+1) << ":" << std::endl;
            for(int j=0; j<lines[i].n; j++){
              /*   if(getNum(lines[i].mas[j]) < 0){
                    erase(lines, i+1);
                    return nullptr; */
                    lines[i].mas[j]=nullptr;
                }
            }

        int k=-1;
        int i=0, j=0;
        int* tmp=nullptr;
        int val=0;
        do{
            std::cout<< "Do you want to input? 0 - if No , Any other number - if Yes"<<std::endl;
            if(getNum(k) < 0)
                return nullptr;
            if(k == 0) break;

            std::cout<< "Input the raw index:"<<std::endl;
            if(getNum(i) < 0)
                return nullptr;
            i--;
            if(i>m){
                std::cout<<"Invalid raw index"<<std::endl;
                continue;
            }

            std::cout << "Input the column index:" << std::endl;
            if(getNum(j) < 0)
                return nullptr;
            j--;
            if(j>lines[i].n){
                std::cout<<"Invalid column index"<<std::endl;
                continue;
            }

            if(lines[i].mas[j]!=nullptr){
                std::cout<<"Bruh, this element is already taken" << std::endl;
                continue;
            }

            std::cout<<"Input the value:"<<std::endl;
            if(getNum(val) < 0)
                return nullptr;
            tmp=new int[1];
            *tmp=val;
            lines[i].mas[j]=tmp;
            val=0;
            tmp=nullptr;
        }while(k!=0);
        rm=m;
        return lines;
        }

    void output(const char *msg, Line *a, int m){
        int i,j;
        std::cout << msg << std::endl;
        for(i=0;i<m;++i){
            for(j=0;j<a[i].n;++j){
                if(a[i].mas[j] == nullptr){
                    std::cout << 0 << " ";
                    continue;
                }
                std::cout << *(a[i].mas[j]) << " ";
            }
            std::cout << std::endl;
        }
    }

    Line *erase(Line *&lines, int m){
        int i;
        for(i=0;i < m; i++){
            for(int j=0; j< lines[i].n;j++){
                    if(lines[i].mas[j]!=nullptr) delete lines[i].mas[j];
            }
            //delete[] lines[i].mas;
        }
        delete[] lines;
        return nullptr;
    }
    int is_even(int num){
        while((num%2 == 0) && (num != 0) &&(num != -1) && (num != 1)){
            num=num/10;
        }
        if(num == 0) return 1;
        else return -1;
    }
    Line* process(int i, Line *&lines, int(*f)(int )){
        int k=0, k2=0;
        int *temp=nullptr, elements=0;
        elements=lines[i].n;
        for(int j=0; j < (elements); j++){
        if(lines[i].mas[j]!=nullptr){
        k=f(*(lines[i].mas[j]));
        } else continue;
        if(k<0){
            std::cout << "Kek" <<std::endl;
            //for(int l=j+1; l < (elements);l++){
                std::cout<<"crazy"<<std::endl;
              //  if(lines[i].mas[l]!=nullptr){
                    //if(f((lines[i].mas[l])) < 0){
                        /*temp=lines[i].mas[j];
                        lines[i].mas[j]=lines[i].mas[l];
                        lines[i].mas[l]=temp;
                        std::cout << "lmao" << std::endl;
                        break; */
                        delete lines[i].mas[j];
                        lines[i].mas[j] = nullptr;
                  //  }
               // }
           //}
        }
        }
        /* for(int j=0; j < elements; j++){
           if(f(*(lines[i].mas[j])) < 0) lines[i].n--;
        } */
        return lines;
    }
    int count_real(Line mas){
        int count=0;
        for(int i=0;i < mas.n;i++){
            if( mas.mas[i] != nullptr ) count++;
        }
        return count;
    }
    Line* sort(Line *&lines, int m){
        Line temp;
        for(int i=0;i < m;i++){
            for(int j=0; j < m;j++){
                if(count_real(lines[i]) < count_real(lines[j])){
                        temp=lines[j];
                        lines[j]=lines[i];
                        lines[i]=temp;
                }
            }
        }
        return lines;
    }

}
