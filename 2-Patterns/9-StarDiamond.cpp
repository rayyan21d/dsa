void nStarDiamond(int n) {

    for(int i=0;i<n;i++){

        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=0; j<2*i+1;j++){
            cout << "*";
        }
        for(int j=0; j<n-i-1;j++ ){
            cout << " ";
        }

        cout << "\n";

    }




    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<i-1; j++)
        {
            cout << " ";

        }
        for (int k=(n*2+1); k>i*2; k--)
        {cout << "*" ;}
        for (int j=0; j<i-1; j++)
        {
            cout << " ";

        }
        cout << endl;
    }

}
