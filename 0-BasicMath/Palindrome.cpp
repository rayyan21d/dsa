bool palindrome(int n)
{
    int x=n;
    int temp=0;
    int rev=0;

   
    while(x>0){

        temp = x%10;
        rev = temp+(rev)*10;
        x=x/10;
    }

    if(rev==n){
        return true;
    }else{
        return false;
    }

    

}
