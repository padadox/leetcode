

class Solution {
    public int sumSubseqWidths(int[] a) {
        int mod = 1000000007;
        Arrays.sort(a);
        int n = a.length;
        // a[n-2]*1+a[n-1]*2
        long s = 0;
        long num = 0;
        long ans = 0;
        for(int i = n-1;i >= 1;i--){
            s = s * 2 + a[i];
            num = num * 2 + 1;

            s %= mod;
            num %= mod;
            ans += s - num * a[i-1];
            ans %= mod;
        }
        if(ans < 0)ans += mod;
        return (int)ans;
    }
};	
