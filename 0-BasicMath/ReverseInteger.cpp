int reverse(int x){
   
    int temp=0;
    int rev=0;
    
    while(x>0){
        temp = x%10;
        rev = temp+(rev)*10;
        x=x/10;
    }
  
    return rev;
}
