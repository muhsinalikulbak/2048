#include "spawn_tile.h"

static int count_empty_cells(int board[4][4])
{
    int count = 0;
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            if (board[i][j] == 0)
                count++;
    return count;
}

void spawn_tile(t_data *d)
{
    int empty_count = count_empty_cells(d->board);
    if (empty_count == 0)
        return;
        
    int rnd_num = rand() % empty_count + 1;
    int count = 0;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (d->board[i][j] == 0)
            {
                count++;
                if (count == rnd_num)
                {
                    d->board[i][j] = rand() % 10 == 0 ? 4 : 2;
                    return;
                }
            }
        }
    }
}


// Oyunda 2'e 4'den yüzde doksan daha sık görünmeli
// Yani 2 yüzde doksan sıklıkla görünürken, 4 yüzde on sıklıkla görünmeli.
// rand() % 10 == 0 ? 4 : 2 yeterlidir.

// Örneğin 1-100 arası 100 sayının 10 adet 10 böleni vardır.
// Bu demektir ki N adet sayının yüzde 10 'U her zaman 10'a bölünen sayılardır.
// Geri kalan yüzde 90 ise bölünmeyen.
// Yani 100 adet random sayı çağırıp kontrol edersek bu olasılığı yakalayacağız.
// İşte bunu kullanabiliriz. Gelen sayının 10'a bölünme ihtimali yüzde 10 olduğu için
// 10'a bölünüyorsa 4, bölünmüyorsa 2 yapacağız.
