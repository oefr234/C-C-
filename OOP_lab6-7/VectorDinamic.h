#pragma once
#include <iostream>
#include "Masina.h"
using namespace  std;
//tip de data generic (pentru moment este intreg)

template <typename TElem> class VectorDinamic {

private:
    //capacitate
    int cp;
    //dimensiune
    int n;
    //elemente
    TElem* e;
    //pentru redimensionare
    void redim() {

        //alocam un spatiu de capacitate dubla
        TElem* eNou = new TElem[2 * cp];

        //copiem vechile valori in noua zona
        for (int i = 0; i < n; i++)
            eNou[i] = e[i];

        //dublam capacitatea
        cp = 2 * cp;

        //eliberam vechea zona
        delete[] e;

        //vectorul indica spre noua zona
        e = eNou;
    }

public:
    //pentru ca Iteratorul sa poata accesa reprezentarea vectorului
    //constructor
    VectorDinamic(int cp)
    {
        //setam capacitatea
        this->cp = cp;

        //alocam spatiu de memorare pentru vector
        e = new TElem[cp];

        //setam numarul de elemente
        this->n = 0;
    }

    ~VectorDinamic() {
        //eliberam zona de memorare alocata vectorului
        delete[] e;
    }

    VectorDinamic(const VectorDinamic& v)
    {
        this->cp = v.cp;   // Copy the capacity
        this->n = v.n;     // Copy the size
        e = new TElem[cp]; // Allocate new memory

        for (int i = 0; i < n; i++)
            e[i] = v.e[i]; // Copy elements
    }

    VectorDinamic& operator=(VectorDinamic&& other) noexcept {
        if (this != &other) {
            delete[] e;
            cp = other.cp;
            n = other.n;
            e = other.e;
            other.e = nullptr;
            other.n = 0;
            other.cp = 0;
        }
        return *this;
    }

    bool empty() {
        if (n == 0)
            return true;
        return false;
    }

    TElem& operator[](int i)
    {
        return element(i);
    }
    const TElem& operator[](int i) const {
        return element(i);
    }

    int dim() const {
        return n;
    }

    TElem& element(int i) {
        return e[i];
    }

    const TElem& element(int i) const {
        return e[i];
    }
    void adaugaSfarsit(TElem e) {
        //daca s-a atins capacitatea maxima, redimensionam
        if (n == cp)
            redim();

        //adaugam la sfarsit
        this->e[n++] = e;
    }


    bool sterge(TElem elem) {
        for (int i = 0; i < dim(); i++)
        {
            if (this->e[i].getNumarInmatriculare() == elem.getNumarInmatriculare()) {
                for (int k = i; k < dim() - 1; k++)
                    this->e[k] = this->e[k + 1];
                this->n--;
                return true;
            }
        }
        return false;
    }

    bool cauta(TElem elem) const {
        for (int i = 0; i < dim(); i++)
        {
            if (e[i] == elem)
                return true;
        }
        return false;
    }
};