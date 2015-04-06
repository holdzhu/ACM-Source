import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigDecimal r;
		int n;
		while (cin.hasNextBigDecimal()) {
			r = cin.nextBigDecimal();
			n = cin.nextInt();
			BigDecimal ans = BigDecimal.ONE;
			for (int i = 0; i < n; ++i) {
				ans = ans.multiply(r);
			}
			ans = ans.stripTrailingZeros();
			String s = ans.toPlainString();
			if (s.startsWith("0.")) {
				s = s.substring(1);
			}
			System.out.println(s);
		}
	}
}