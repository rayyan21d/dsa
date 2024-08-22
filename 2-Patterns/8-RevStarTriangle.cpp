void nStarTriangle(int n) {
    for(int i=n;i>0;i--){

        int nspace=n-i;
        int nstar=2*i-1;

        std::string space(nspace, ' ');
        std::string stars(nstar, '*');

        std::cout << space << stars << space;

        std::cout << '\n';
    
    }
}
