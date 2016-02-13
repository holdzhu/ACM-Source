import java.io.*;
import java.util.*;
import java.math.*;

class Main {

	static final int maxsum = 50 * 51 / 2;
	static long[][] dp = new long[51][maxsum + 1];
	static long[] ans = new long[maxsum + 1];

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while (t-- > 0) {
			int n = input.nextInt();
			int sum = n * (n + 1) / 2;
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= sum; ++j) {
					dp[i][j] = 0;
				}
			}
			for (int i = 0; i <= sum; ++i) {
				ans[i] = 0;
			}
			dp[0][sum] = -1;
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= sum; ++j) {
					ans[j] += dp[i][j];
					for (int k = i + 1; k <= n; ++k) {
						if (j >= n - i + (k - i - 1) * (n - k)) {
							dp[k][j - n + i - (k - i - 1) * (n - k)] -= dp[i][j];
						}
					}
				}
			}
			BigDecimal out = BigDecimal.ZERO;
			out.setScale(150);
			for (int i = 0; i < sum; ++i) {
				out = out.add(BigDecimal.valueOf(ans[i] * sum).divide(BigDecimal.valueOf(sum - i), 150, BigDecimal.ROUND_HALF_UP));
			}
			out = out.setScale(15, BigDecimal.ROUND_HALF_UP);
			System.out.println(out);
		}
	}
}