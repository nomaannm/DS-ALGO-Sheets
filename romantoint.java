public class RomanToInt {
    public static int romantoInt(String s)
    {
        int ans = 0 ;
        int num = 0 ;
        int prev = 0 ;
        for (int i = 0 ; i <= s.length() ; i++ )
        {
            switch(s.charAt(i))
            {
                case 'I' : num = 1 ; break ;
                case 'V' : num = 5 ; break ;
                case 'X' : num = 10 ; break ;
                case 'L' : num = 50 ; break ;
                case 'C' : num = 100 ; break ;
                case 'D' : num = 500 ; break ;
                case 'M' : num = 1000 ; break ;
            }
            if(num < prev)
            {
                ans -= num ;
            }
            else{
                ans += num ;
            }
            prev = num;
        }
        return ans;
    }

    public static void main(String s[])
    {
       System.out.println(romantoInt("XIV"));
    }
    
}
