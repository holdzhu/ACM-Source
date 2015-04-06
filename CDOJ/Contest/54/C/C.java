import java.io.*;
import java.util.*;
import java.math.*;

public class C {
	static BigInteger C(int x, long y)
	{
		BigInteger ans = BigInteger.ONE;
		for (int i = 1; i <= x; ++i)
		{
			ans = ans.multiply(BigInteger.valueOf(y - i + 1));
			ans = ans.divide(BigInteger.valueOf(i));
		}
		return ans;
	}
	static int F(BigInteger x,BigInteger y)
	{
	    int tot=0;
	    while(x.mod(y) == BigInteger.ZERO)
	    {
	       tot++;
	       x = x.divide(y);
	    }
	    return tot;
	}
	public static void main(String[] args) {
		long t, m;
		t = 7;
		for (m = t; m < 1000; m += t)
		{
			long s = 1;
			while (s * t < m)
			{
				s *= t;
			}
			long s2 = s;
			while (s2 + s <= m)
			{
				s2 += s;
			}
			long max = 0;
			long maxc = -1;
			for (int i = 0; i <= m; ++i)
			{
				int bi = F(C(i, m), BigInteger.valueOf(t));
				if (bi >= max)
				{
					max = bi;
					maxc = i;
				}
			}
			System.out.println(maxc + " " + (s2 - 1));
			if (maxc != s2 - 1) {
				System.out.println("!!!");
				break;
			}
		}
	}
}