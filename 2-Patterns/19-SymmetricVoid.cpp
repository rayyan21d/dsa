void symmetry(int n) {

    for(int i=0;i<2*n;i++){

        if(i<n){

            
            for(int j=0; j<2*n ;j++){
                
                string star ="* ";
                if(j>i && j<2*n-i){
                    string star="  ";
                }

                cout << star;
            }

            cout << endl;


        }

    

    }


}
