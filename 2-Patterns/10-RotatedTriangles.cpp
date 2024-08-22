void nStarTriangle(int n) {

    int y = 2*n -1;
    for(int i=1;i<=y;i++){

        int stars = i;
        if(i>n) stars = 2*n -i;
        for (int j=0; j<stars ; j++) {

            cout << '*';
        }

        cout << endl;
    
    }
 

   
}
