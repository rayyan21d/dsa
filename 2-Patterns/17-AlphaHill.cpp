void alphaHill(int n) {

    for(int i=1;i<=n;i++){

        for(int j=0;j<n-i+1;j++){
            cout << "  ";
        }
        for(int j=1,t=0,k=1;j<=2*i-1;j++){

            if(j<=i){
                cout << char(64+j)<< " ";
                t=64+j;
            }else{
                cout << char(t-k)<<" ";
                k--;
            }
            
        }
        for(int j=0;j<n-i+1;j++){
            cout << "  ";
        }

        cout << '\n';
    }
}
