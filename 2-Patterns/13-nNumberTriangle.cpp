void nNumberTriangle(int n) {
    int x=1;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=i;j++,x++){
            cout << x<< ' ';
        }
        cout << endl;
    }
}
