import java.io.*;
import java.math.*;
import java.util.*;

public class CalcPi {
	private static final int round = 1000000;
	public static void main(String[] args) {
		BigDecimal pi = BigDecimal.ZERO;
		for (int i = 0; ; ++i) {
			BigDecimal divisor = BigDecimal.valueOf(2).pow(10 * i + 6);
			BigDecimal s0 = BigDecimal.valueOf(32).divide(BigDecimal.valueOf(-4 * i - 1).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal s1 = BigDecimal.valueOf(1).divide(BigDecimal.valueOf(-4 * i - 3).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal s2 = BigDecimal.valueOf(256).divide(BigDecimal.valueOf(10 * i + 1).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal s3 = BigDecimal.valueOf(64).divide(BigDecimal.valueOf(-10 * i - 3).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal s4 = BigDecimal.valueOf(4).divide(BigDecimal.valueOf(-10 * i - 5).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal s5 = BigDecimal.valueOf(4).divide(BigDecimal.valueOf(-10 * i - 7).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal s6 = BigDecimal.valueOf(1).divide(BigDecimal.valueOf(10 * i + 9).multiply(divisor), round, BigDecimal.ROUND_DOWN);
			BigDecimal tmp = s0.add(s1).add(s2).add(s3).add(s4).add(s5).add(s6);
			if (tmp.compareTo(BigDecimal.valueOf(0)) == 0) {
				break;
			}
			if (i % 2 == 1) {
				tmp = tmp.multiply(BigDecimal.valueOf(-1));
			}
			pi = pi.add(tmp);
		}
		System.out.println(pi);
	}
}
