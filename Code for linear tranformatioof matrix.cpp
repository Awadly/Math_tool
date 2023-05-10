#include <iostream>
#include <vector>
using namespace std;

vector<long long> extended_euclid_gcd(long long a, long long b) {
    // Returns a vector `result` of size 3 where:
    // Referring to the equation ax + by = gcd(a, b)
    //     result[0] is gcd(a, b)
    //     result[1] is x
    //     result[2] is y 
    
    long long s = 0; long long old_s = 1;
    long long t = 1; long long old_t = 0;
    long long r = b; long long old_r = a;

    while(r != 0) {
        long long quotient = old_r/r;
        // We are overriding the value of r, before that we store it"s current
        // value in temp variable, later we assign it to old_r
        long long temp = r;
        r = old_r - quotient*r;
        old_r = temp;

        // We treat s and t in the same manner we treated r
        temp = s;
        s = old_s - quotient*s;
        old_s = temp;

        temp = t;
        t = old_t - quotient*t;
        old_t = temp;
    }
    vector<long long> result;
    result.push_back(old_r);
    result.push_back(old_s);
    result.push_back(old_t);
    return result;
}

int main() {
    int p,q,r,s,a,b;
    cin>>p>>q>>r>>s;
    if(p*s-q*r==1||p*s-q*r==-1){
        cout<<"good matrix"<<endl;
    }
    else{
        cout<<"bad matrix"<<endl;
    }
    cout<<"enter a pair of relatively prime numbers";
    cin>>a>>b;
    cout<< "the numbers after transformation are "<<p*a+q*b<<" and "<<r*a+s*b<<endl;
    vector<long long> res;
    res = extended_euclid_gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is " << res[0] << ". x = " << res[1] << " and y = " << res[2]<<endl;
    cout<< "The new coefficients are "<< res[1]*s-r*res[2] << " and "<< p*res[2]-q*res[1];
    return 0;}