int like[2100][2100];
int cnt[2100];
int happy[2100];
int malted[2100];
int Main()
{
  int first_iteration;
  int ans_choice;
  int caseno;
  int res;
  int t;
  int visited;
  int y;
  int res;
  int least;
  int rts;
  int changed;
  int unhappy;
  scanf("%d", &ans_choice);
  for (res = 1; res <= ans_choice; res++)
  {
    for (least = 0; least < 2100; least++)
    {
      malted[least] = 0;
      cnt[least] = 0;
    }

    scanf("%d%d", &caseno, &res);
    for (least = 0; least < res; least++)
    {
      scanf("%d", &t);
      cnt[least] = t;
      for (rts = 0; rts < t; rts++)
      {
        scanf("%d%d", &visited, &y);
        like[least][rts] = visited * ((y * 2) - 1);
      }

    }

    changed = 1;
    while (changed)
    {
      unhappy = 0;
      changed = 0;
      for (least = 0; least < res; least++)
      {
        happy[least] = 0;
      }

      for (least = 0; least < res; least++)
      {
        for (rts = 0; rts < cnt[least]; rts++)
        {
          if ((like[least][rts] > 0) && malted[like[least][rts]])
          {
            happy[least] = 1;
          }
          else
            if ((like[least][rts] < 0) && (!malted[-like[least][rts]]))
          {
            happy[least] = 1;
          }


        }

      }

      for (least = 0; least < res; least++)
      {
        if (!happy[least])
        {
          unhappy++;
          for (rts = 0; rts < cnt[least]; rts++)
          {
            if ((like[least][rts] > 0) && (!malted[like[least][rts]]))
            {
              malted[like[least][rts]] = 1;
              changed = 1;
            }

          }

        }

      }

    }

    if (unhappy)
      printf("Case #%d: IMPOSSIBLE\n", res);
    else
    {
      printf("Case #%d:", res);
      for (least = 1; least <= caseno; least++)
      {
        printf(" %d", malted[least]);
      }

      printf("\n");
    }

  }

}


