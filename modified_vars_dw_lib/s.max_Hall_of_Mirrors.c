#include <stdio.h>
int gcd(int k, int flg)
{
  int first_iteration;
  if (k < 0)
    k = -k;

  if (flg < 0)
    flg = -flg;

  int n;
  while (flg)
  {
    n = k % flg;
    k = flg;
    flg = n;
  }

  return k;
}

int Main()
{
  int first_iteration;
  int s;
  int p_g;
  scanf("%d", &s);
  for (p_g = 1; p_g <= s; p_g++)
  {
    int h;
    int w;
    int r;
    int k;
    int y;
    int gr_major;
    int j;
    char niz[50][50];
    int bio[200][200] = {0};
    scanf("%d %d %d", &h, &w, &r);
    for (gr_major = 0; gr_major < h; gr_major++)
      scanf("%s", niz[gr_major]);

    for (gr_major = 1; gr_major < (h - 1); gr_major++)
      for (j = 1; j < (w - 1); j++)
      if (niz[gr_major][j] == 'X')
    {
      k = gr_major - 1;
      y = j - 1;
    }



    double now = k + 0.5;
    double openssl_s390xcap_p = y + 0.5;
    int ukupno = 0;
    for (gr_major = -r; gr_major <= r; gr_major++)
      for (j = -r; j <= r; j++)
    {
      double targetp;
      double gss_c_ma_oos_det;
      if ((gr_major == 0) && (j == 0))
        continue;

      targetp = !(gr_major & 1) ? now : (h - 2) - now;
      targetp += gr_major * (h - 2);
      gss_c_ma_oos_det = !(j & 1) ? openssl_s390xcap_p : (w - 2) - openssl_s390xcap_p;
      gss_c_ma_oos_det += j * (w - 2);
      if ((((targetp - now) * (targetp - now)) + ((gss_c_ma_oos_det - openssl_s390xcap_p) * (gss_c_ma_oos_det - openssl_s390xcap_p))) <= (r * r))
      {
        int ux = targetp - now;
        int uy = gss_c_ma_oos_det - openssl_s390xcap_p;
        int person = gcd(ux, uy);
        ux /= person;
        uy /= person;
        ux += 100;
        uy += 100;
        if (!bio[ux][uy])
          ukupno++;

        bio[ux][uy] = 1;
      }

    }


    printf("Case #%d: %d\n", p_g, ukupno);
  }

  return 0;
}


