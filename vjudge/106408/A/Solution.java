import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		BigInteger dp0 = BigInteger.ZERO;
		BigInteger dp1 = BigInteger.ONE;
		while (m-- > 0) {
			BigInteger dp = dp0.multiply(BigInteger.valueOf(2)).add(dp1.multiply(BigInteger.valueOf(n)));
			dp1 = dp0;
			dp0 = dp;
		}
		System.out.println(dp1);
	}
}