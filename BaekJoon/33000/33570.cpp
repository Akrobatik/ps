// Title : Lunatic Mine
// Link  : https://www.acmicpc.net/problem/33570 
// Time  : 1000 ms
// Memory: 13748 KB

#include <bits/stdc++.h>

using namespace std;

// #define DEBUG

constexpr int64_t kInf = INT64_MAX;

static constexpr int64_t kSmeltCost[] = {
    1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,            //
    11000, 12000, 13000, 14000, 15000, 20000, 22500, 25000, 27500, 30000,   //
    35000, 40000, 45000, 50000, 60000, 70000, 80000, 90000, 100000, 200000  //
};

static constexpr int64_t kSmeltProb[] = {
    100, 95, 90, 85, 80, 80, 80, 80, 80, 80,  //
    70, 60, 50, 40, 30, 30, 30, 30, 30, 30,   //
    25, 20, 15, 10, 5, 5, 4, 3, 2, 1          //
};

static constexpr int64_t kCraftCost[] = {
    0, 1250, 2500, 5000, 10000  //
};

static constexpr int64_t kRankUpProb[] = {
    0, 16, 9, 4, 1  //
};

static constexpr int64_t kRankUpFailReward[] = {
    0, 1, 2, 4, 8  //
};

static constexpr int64_t kEnchantCost[] = {
    1000, 3000, 8000, 15000, 50000  //
};

static constexpr int64_t kEnchantMagicIds[5][19] = {
    {7, 1, 4, 7, 10, 13, 14, 17},                                         //
    {10, 1, 2, 4, 5, 7, 8, 10, 13, 14, 17},                               //
    {12, 1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17},                       //
    {18, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},  //
    {18, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},  //
};

static constexpr int64_t kBaseLunaMin[] = {
    1, 100, 200, 300, 400, 500, 600, 700, 800, 900,                       //
    1000, 1200, 1500, 1900, 2400, 3000, 3500, 4000, 4500, 5000,           //
    5500, 7000, 8000, 9000, 10000, 11000, 13000, 15000, 17000, 19000,     //
    20000, 22000, 24000, 26000, 29000, 32000, 35000, 40000, 45000, 50000  //
};

static constexpr int64_t kBaseLunaMax[] = {
    100, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800,                        //
    2000, 2400, 3000, 3800, 4800, 6000, 7000, 8000, 9000, 10000,                  //
    11000, 14000, 16000, 18000, 20000, 20000, 20000, 20000, 20000, 20000, 20000,  //
    22000, 24000, 26000, 29000, 32000, 35000, 40000, 45000, 50000                 //
};

static constexpr int64_t kBaseMoon[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                                       //
    0, 100, 200, 300, 400, 500, 700, 900, 1100, 1300,                   //
    1500, 2000, 2500, 3000, 3500, 4000, 5000, 6000, 7000, 8000, 10000,  //
    12000, 14000, 16000, 19000, 22000, 25000, 30000, 35000, 50000       //
};

static constexpr int64_t kBaseDrop[5][40] = {
    {
        0, 0, 0, 0, 0, 0, 1, 2, 3, 4,              //
        5, 7, 9, 11, 13, 15, 16, 17, 18, 19,       //
        20, 22, 24, 26, 28, 30, 34, 38, 42, 46,    //
        50, 55, 60, 65, 75, 85, 95, 100, 200, 400  //
    },
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,            //
        0, 0, 0, 0, 0, 0, 1, 2, 3, 4,            //
        5, 7, 9, 11, 13, 15, 18, 21, 24, 27,     //
        30, 35, 40, 45, 52, 59, 66, 76, 86, 100  //
    },
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           //
        0, 1, 2, 3, 4, 5, 7, 9, 11, 13,         //
        15, 18, 21, 24, 28, 32, 36, 40, 45, 50  //
    },
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 25  //
    },
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0   //
    }  //
};

struct RandGen {
  RandGen(int64_t seed) : s(seed), cnt(0) {}

  int64_t RandInt(int64_t l, int64_t r) {
    return l + (Rand() * (r - l + 1) / kMod);
  }

  bool Chance(int64_t p) {
    return RandInt(1, 100) <= p;
  }

  int64_t Choice(span<const int64_t> arr) {
    return arr[RandInt(0, arr.size() - 1)];
  }

  int64_t Rand() {
    ++cnt;
    return s = (s * kMul + kAdd) % kMod;
  }

  int64_t Count() {
    return cnt;
  }

 private:
  static constexpr int64_t kMul = 1664525;
  static constexpr int64_t kAdd = 1013904223;
  static constexpr int64_t kMod = 1LL << 32;

  int64_t s, cnt;
};

struct BaseStat {
  BaseStat() : minn(0), maxx(0), moon(0), drop{} {}

  BaseStat(int64_t lv) {
    assert(0 <= lv && lv <= 39);

    minn = kBaseLunaMin[lv];
    maxx = kBaseLunaMax[lv];
    moon = kBaseMoon[lv];
    for (int i = 0; i < 5; i++) {
      drop[i] = kBaseDrop[i][lv];
    }
  }

  int64_t minn, maxx, moon;
  int64_t drop[5];
};

struct BlessStat {
  BlessStat() : minn(0), maxx(0), moon(0), drop{} {}

  BlessStat(int64_t lv) : BlessStat() {
    int64_t ub = clamp<int64_t>(lv, 0, 20);
    minn = ub * 100;
    maxx = ub * 200;
    moon = ub * 100;
    drop[0] = ub;
    drop[1] = max<int64_t>(lv - 20, 0);
  }

  int64_t minn, maxx, moon, drop[2];
};

struct Magic {
  Magic() : id(0), val(0) {}

  int64_t id, val;
};

struct Axe {
  Axe() : smelt_lv(0), magic_lv(0), magics{} {}

  int64_t GetSmeltCost() {
    assert(smelt_lv <= 29);

    int64_t cost = kSmeltCost[smelt_lv];
    int64_t ratio = 100;
    for (auto e : magics) {
      if (e.id == 17) ratio += e.val;
    }
    return (cost * ratio) / 100;
  }

  int64_t GetSmeltProb() {
    assert(smelt_lv <= 29);
    return kSmeltProb[smelt_lv];
  }

  pair<int64_t, int64_t> GetLunaMinMax(int64_t bless_lv) {
    int64_t lv = smelt_lv;
    for (auto e : magics) {
      if (e.id == 16) lv += e.val;
    }
    lv = clamp<int64_t>(lv, 0, 39);

    BaseStat base(lv);
    BlessStat bless(bless_lv);

    int64_t moon = base.moon + bless.moon;
    for (auto e : magics) {
      if (e.id == 1) {
        moon += e.val;
      } else if (e.id == 2 || e.id == 3) {
        moon += (moon * e.val) / 100;
      }
    }

    int64_t minn = base.minn + bless.minn;
    for (auto e : magics) {
      if (e.id == 4) {
        minn += e.val;
      } else if (e.id == 5 || e.id == 6) {
        minn += (minn * e.val) / 100;
      }
    }

    int64_t maxx = base.maxx + bless.maxx;
    for (auto e : magics) {
      if (e.id == 7) {
        maxx += e.val;
      } else if (e.id == 8 || e.id == 9) {
        maxx += (maxx * e.val) / 100;
      }
    }

    int64_t ratio = 100 + bless.drop[1];
    for (auto e : magics) {
      if (e.id == 10) {
        ratio += e.val;
      } else if (e.id == 11 || e.id == 12) {
        ratio += (ratio * e.val) / 100;
      }
    }

    minn += moon, maxx += moon;
    minn += (minn * (ratio - 100)) / 100;
    maxx += (maxx * (ratio - 100)) / 100;
    return {minn, maxx};
  }

  int64_t ApplyLunaEnergy(int64_t luna) {
    for (auto e : magics) {
      if (e.id == 18) {
        luna += (luna * e.val) / 100;
      }
    }
    return luna;
  }

  array<int64_t, 5> GetStoneDropProb(int64_t bless_lv) {
    int64_t lv = smelt_lv;
    for (auto e : magics) {
      if (e.id == 16) lv += e.val;
    }
    lv = clamp<int64_t>(lv, 0, 39);

    BaseStat base(lv);
    BlessStat bless(bless_lv);

    array<int64_t, 5> drop{};
    for (int i = 0; i < 5; i++) drop[i] = base.drop[i];
    drop[0] += bless.drop[0];

    for (auto e : magics) {
      if (e.id == 13) {
        int idx = (magic_lv <= 1 ? 0 : (magic_lv <= 3 ? 1 : 2));
        drop[idx] += e.val;
      } else if (e.id == 15) {
        for (int i = 0; i < 5; i++) {
          drop[i] += (drop[i] * e.val) / 100;
        }
      }
    }
    return drop;
  }

  int64_t GetLuck() {
    int64_t luck = 1;
    for (auto e : magics) {
      if (e.id == 14) {
        luck += e.val;
      }
    }
    return clamp<int64_t>(luck, 1, 16);
  }

  int64_t GetFinalSmeltLv() {
    int64_t lv = smelt_lv;
    for (auto e : magics) {
      if (e.id == 16) lv += e.val;
    }
    return clamp<int64_t>(lv, 0, 39);
  }

  int64_t smelt_lv;
  int64_t magic_lv;
  Magic magics[3];
};

struct Game {
  Game(int64_t seed) : nq(0), rng(seed), luna(1000), stones{20, 0, 0, 0, 0}, bless_lv(0), bless_stone(0), aidx(0), axes{}, done{} {}

  array<int64_t, 6> Mine() {
    assert(++nq <= kLimit);

#ifndef DEBUG
    cout << "mine" << endl;
    int res;
    cin >> res;
    assert(res == 1);
    array<int64_t, 6> o{};
    for (auto& e : o) cin >> e;
#endif
    auto& axe = axes[aidx];
    auto [minn, maxx] = axe.GetLunaMinMax(bless_lv);
    int64_t luna_add = axe.ApplyLunaEnergy(rng.RandInt(minn, max<int64_t>(minn, maxx)));
    luna += luna_add;

    auto drop = axe.GetStoneDropProb(bless_lv);
    int64_t luck = axe.GetLuck();

    int64_t stone_add[5] = {};
    for (int i = 0; i < 5; i++) {
      int64_t quot = drop[i] / 100;
      int64_t rem = drop[i] % 100;
      stone_add[i] = (quot + (rng.Chance(rem) ? 1 : 0)) * luck;
      stones[i] += stone_add[i];
    }

    array<int64_t, 6> out{};
    out[0] = luna_add;
    for (int i = 0; i < 5; i++) {
      out[i + 1] = stone_add[i];
    }
    Update();
    return out;
  }

  void Equip(int idx) {
    assert(0 <= idx && idx <= 2);
    assert(++nq <= kLimit);

    aidx = idx;

#ifndef DEBUG
    cout << "equip " << idx << endl;

    int res;
    cin >> res;
    assert(res == 1);
#endif
    Update();
  }

  int Smelt() {
    assert(++nq <= kLimit);
#ifndef DEBUG
    cout << "smelt" << endl;

    int res;
    cin >> res;
    assert(-1 <= res && res <= 1);
#endif
    auto& axe = axes[aidx];
    if (axe.smelt_lv >= 30) return -1;

    int64_t cost = axe.GetSmeltCost();
    if (luna < cost) return -1;
    luna -= cost;

    bool ok = rng.Chance(axe.GetSmeltProb());
    if (ok) axe.smelt_lv += 1;
    Update();
    return ok ? 1 : 0;
  }

  int Craft(int rank) {
    assert(1 <= rank && rank <= 4);
    assert(++nq <= kLimit);
#ifndef DEBUG
    cout << "craft " << rank << endl;

    int res;
    cin >> res;
    assert(res == -1 || res == 1);
#endif
    int64_t cost = kCraftCost[rank];
    if (stones[rank - 1] < 2 || luna < cost) return -1;
    stones[rank - 1] -= 2, stones[rank] += 1;
    luna -= cost;

    Update();
    return 1;
  }

  int RankUp() {
    assert(++nq <= kLimit);
#ifndef DEBUG
    cout << "rank_up" << endl;

    int res;
    cin >> res;
    assert(-1 <= res && res <= 1);
#endif
    auto& axe = axes[aidx];
    int dst = axe.magic_lv + 1;
    if (!(1 <= dst && dst <= 4) || stones[dst] <= 0) return -1;
    stones[dst] -= 1;

    bool ok = rng.Chance(kRankUpProb[dst]);
    if (ok) {
      axe.magic_lv += 1;
      for (auto& e : axe.magics) e = Magic();
    } else {
      AddBlessStone(kRankUpFailReward[dst]);
    }
    Update();
    return ok ? 1 : 0;
  }

  int Enchant() {
    assert(++nq <= kLimit);
#ifndef DEBUG
    cout << "enchant" << endl;

    int res;
    cin >> res;
    if (res == 1) {
      auto& axe = axes[aidx];
      for (auto& e : axe.magics) cin >> e.id >> e.val;
    }
#endif
    assert(++nq <= kLimit);

    auto& axe = axes[aidx];
    int64_t cost = kEnchantCost[axe.magic_lv];
    if (luna < cost) return -1;
    luna -= cost;

    for (auto& e : axe.magics) {
      auto ids = kEnchantMagicIds[axe.magic_lv];
      span<const int64_t> cands(ids + 1, ids[0]);

      int64_t id = rng.Choice(cands);
      int64_t val = RollMagicValue(axe.magic_lv, id);
      e.id = id, e.val = val;
    }
    Update();
    return 1;
  }

  void Exit() {
#ifndef DEBUG
    cout << "exit" << endl;
#endif
    Update();
  }

  bool IsDone() {
    bool ok = true;
    for (auto b : done) ok &= b;
    return ok;
  }

  bool IsDone(int idx) {
    return done[idx];
  }

  int GetRemQuries() {
    return kLimit - nq;
  }

  int64_t GetRandCount() {
    return rng.Count();
  }

  int64_t GetLuna() {
    return luna;
  }

  int64_t GetStone(int idx) {
    return stones[idx];
  }

  int64_t GetStoneNeeded(int idx) {
    if (!(3 <= idx && idx <= 4)) return 0;

    int64_t c4 = stones[4], c3 = (stones[4] << 1) + stones[3];
    for (auto e : axes) {
      if (e.magic_lv == 4) {
        c4 += 1, c3 += 2;
      } else if (e.magic_lv == 3) {
        c3 += 1;
      }
    }

    if (idx == 3) return max<int64_t>(9 - c3, 0);
    return max<int64_t>(3 - c4, 0);
  }

  int64_t GetBlessLv() {
    return bless_lv;
  }

  Axe GetAxe(int idx) {
    return axes[idx];
  }

 private:
  static constexpr int kLimit = 20000;

  void AddBlessStone(int64_t inc) {
    bless_stone += inc;
    while (bless_stone >= bless_lv + 1) {
      bless_stone -= bless_lv + 1;
      bless_lv += 1;
    }
  }

  int64_t RollMagicValue(int64_t magic_lv, int64_t magic_id) {
    switch (magic_id) {
      case 1: {
        if (magic_lv == 0) return rng.RandInt(1, 100);
        if (magic_lv == 1) return rng.RandInt(1, 300);
        if (magic_lv == 2) return rng.RandInt(1, 500);
        if (magic_lv == 3) return rng.RandInt(500, 700);
        return rng.RandInt(700, 1500);
      } break;

      case 2: {
        if (magic_lv == 1) return rng.RandInt(10, 50);
        if (magic_lv == 2) return rng.RandInt(10, 100);
        if (magic_lv == 3) return rng.RandInt(100, 150);
        return rng.RandInt(150, 200);
      } break;

      case 3: {
        return 200;
      } break;

      case 4: {
        if (magic_lv == 0) return rng.RandInt(1, 100);
        if (magic_lv == 1) return rng.RandInt(1, 400);
        if (magic_lv == 2) return rng.RandInt(1, 800);
        if (magic_lv == 3) return rng.RandInt(800, 1200);
        return rng.RandInt(1200, 2000);
      } break;

      case 5: {
        if (magic_lv == 1) return rng.RandInt(10, 50);
        if (magic_lv == 2) return rng.RandInt(10, 100);
        if (magic_lv == 3) return rng.RandInt(100, 150);
        return rng.RandInt(150, 200);
      } break;

      case 6: {
        return 200;
      } break;

      case 7: {
        if (magic_lv == 0) return rng.RandInt(2, 200);
        if (magic_lv == 1) return rng.RandInt(200, 800);
        if (magic_lv == 2) return rng.RandInt(800, 1600);
        if (magic_lv == 3) return rng.RandInt(1600, 2400);
        return rng.RandInt(2400, 4000);
      } break;

      case 8: {
        if (magic_lv == 1) return rng.RandInt(10, 50);
        if (magic_lv == 2) return rng.RandInt(50, 100);
        if (magic_lv == 3) return rng.RandInt(100, 150);
        return rng.RandInt(150, 200);
      } break;

      case 9: {
        return 200;
      } break;

      case 10: {
        if (magic_lv == 0) return rng.RandInt(1, 5);
        if (magic_lv == 1) return rng.RandInt(5, 10);
        if (magic_lv == 2) return rng.RandInt(10, 25);
        if (magic_lv == 3) return rng.RandInt(25, 50);
        return rng.RandInt(50, 100);
      } break;

      case 11: {
        if (magic_lv == 2) return rng.RandInt(1, 10);
        if (magic_lv == 3) return rng.RandInt(10, 50);
        return rng.RandInt(50, 100);
      } break;

      case 12: {
        return 200;
      } break;

      case 13: {
        if (magic_lv <= 1) return rng.RandInt(1 + (magic_lv == 1 ? 4 : 0), 5 + (magic_lv == 1 ? 5 : 0));
        if (magic_lv == 2) return rng.RandInt(5, 10);
        if (magic_lv == 3) return rng.RandInt(10, 20);
        return rng.RandInt(20, 25);
      }

      case 14: {
        return 1 + magic_lv;
      } break;

      case 15: {
        return 200;
      } break;

      case 16: {
        if (magic_lv == 2) return 1;
        if (magic_lv == 3) return 2;
        return 3;
      } break;

      case 17: {
        static const int64_t kDiscount[5] = {-5, -10, -15, -20, -25};
        return kDiscount[magic_lv];
      } break;

      case 18: {
        return 200;
      } break;
    }
    assert(0);
    return 0;
  }

  void Update() {
    for (int i = 0; i < 10; i++) {
      if (done[i]) continue;

      switch (i) {
        case 0: {
          done[i] = (luna == 0);
        } break;

        case 1: {
          for (auto e : axes) {
            done[i] |= (e.smelt_lv == 30);
          }
        } break;

        case 2: {
          for (auto e : axes) {
            done[i] |= (e.magic_lv == 4);
          }
        } break;

        case 3: {
          for (auto e : axes) {
            auto [minn, maxx] = e.GetLunaMinMax(bless_lv);
            done[i] |= (maxx - minn >= 100000);
          }
        } break;

        case 4: {
          for (auto e : axes) {
            auto [minn, maxx] = e.GetLunaMinMax(bless_lv);
            done[i] |= (maxx - minn < 0);
          }
        } break;

        case 5: {
          for (auto e : axes) {
            auto drop = e.GetStoneDropProb(bless_lv);
            for (auto prob : drop) {
              done[i] |= (prob > 100);
            }
          }
        } break;

        case 6: {
          int cnt = 0;
          for (auto e : axes) {
            cnt += (e.magic_lv == 4);
          }
          done[i] = (cnt == 3);
        } break;

        case 7: {
          done[i] = (luna >= 100000000);
        } break;

        case 8: {
          int64_t sum = 0;
          for (auto e : axes) {
            sum += e.GetFinalSmeltLv();
          }
          done[i] = (sum >= 100);
        } break;

        case 9: {
          for (auto e : axes) {
            done[i] |= (e.GetFinalSmeltLv() == 39);
          }
        } break;
      }
    }
  }

  int nq;
  RandGen rng;

  int64_t luna;
  int64_t stones[5];

  int64_t bless_lv;
  int64_t bless_stone;

  int aidx;
  Axe axes[3];

  bool done[10];
};

struct Simulator {
  Simulator(int64_t seed) : arr(kMax) {
    RandGen rng(seed);
    for (auto& e : arr) e = rng.Rand();
  }

  int64_t RandInt(int64_t l, int64_t r, int64_t cnt) {
    return l + (arr[cnt] * (r - l + 1) / kMod);
  }

  bool Chance(int64_t p, int64_t cnt) {
    return RandInt(1, 100, cnt) <= p;
  }

  int64_t Choice(span<const int64_t> arr, int64_t cnt) {
    return arr[RandInt(0, arr.size() - 1, cnt)];
  }

  bool CanAchieve4(Axe axe, int64_t luna, int64_t bless_lv, int64_t cnt) {
    int64_t cost = kEnchantCost[axe.magic_lv];
    if (luna < cost) return false;

    RollMagic(axe, cnt);
    auto [minn, maxx] = axe.GetLunaMinMax(bless_lv);
    return (maxx - minn) >= 100000;
  }

  bool CanAchieve5(Axe axe, int64_t luna, int64_t bless_lv, int64_t cnt) {
    int64_t cost = kEnchantCost[axe.magic_lv];
    if (luna < cost) return false;

    RollMagic(axe, cnt);
    auto [minn, maxx] = axe.GetLunaMinMax(bless_lv);
    return (maxx - minn) < 0;
  }

  bool CanAchieve6(Axe axe, int64_t luna, int64_t bless_lv, int64_t cnt) {
    int64_t cost = kEnchantCost[axe.magic_lv];
    if (luna < cost) return false;

    RollMagic(axe, cnt);
    auto drop = axe.GetStoneDropProb(bless_lv);
    return *max_element(drop.begin(), drop.end()) > 100;
  }

  bool CanAchieve9(Axe axe, int64_t luna, int64_t bless_lv, int64_t cnt) {
    int64_t cost = kEnchantCost[axe.magic_lv];
    if (luna < cost) return false;

    int64_t old = axe.GetFinalSmeltLv();
    RollMagic(axe, cnt);
    return axe.GetFinalSmeltLv() > old;
  }

  vector<int> GetAch10Events(int64_t cnt) {
    vector<int> res;
    for (int i = cnt; i + 3 <= kMax; i++) {
      bool ok = true;
      for (int j = 0; ok && j < 3; j++) {
        auto ids = kEnchantMagicIds[4];
        span<const int64_t> cands(ids + 1, ids[0]);
        int64_t id = Choice(cands, i + j);
        ok = (id == 16);
      }
      if (ok) res.push_back(i);
    }
    return res;
  }

 private:
  static constexpr int64_t kMax = 120000;
  static constexpr int64_t kMod = 1LL << 32;

  void RollMagic(Axe& axe, int64_t cnt) {
    for (auto& e : axe.magics) {
      auto ids = kEnchantMagicIds[axe.magic_lv];
      span<const int64_t> cands(ids + 1, ids[0]);

      int64_t id = Choice(cands, cnt++);
      int64_t val = RollMagicValue(axe.magic_lv, id, cnt);
      e.id = id, e.val = val;
    }
  }

  int64_t RollMagicValue(int64_t magic_lv, int64_t magic_id, int64_t& cnt) {
    switch (magic_id) {
      case 1: {
        if (magic_lv == 0) return RandInt(1, 100, cnt++);
        if (magic_lv == 1) return RandInt(1, 300, cnt++);
        if (magic_lv == 2) return RandInt(1, 500, cnt++);
        if (magic_lv == 3) return RandInt(500, 700, cnt++);
        return RandInt(700, 1500, cnt++);
      } break;

      case 2: {
        if (magic_lv == 1) return RandInt(10, 50, cnt++);
        if (magic_lv == 2) return RandInt(10, 100, cnt++);
        if (magic_lv == 3) return RandInt(100, 150, cnt++);
        return RandInt(150, 200, cnt++);
      } break;

      case 3: {
        return 200;
      } break;

      case 4: {
        if (magic_lv == 0) return RandInt(1, 100, cnt++);
        if (magic_lv == 1) return RandInt(1, 400, cnt++);
        if (magic_lv == 2) return RandInt(1, 800, cnt++);
        if (magic_lv == 3) return RandInt(800, 1200, cnt++);
        return RandInt(1200, 2000, cnt++);
      } break;

      case 5: {
        if (magic_lv == 1) return RandInt(10, 50, cnt++);
        if (magic_lv == 2) return RandInt(10, 100, cnt++);
        if (magic_lv == 3) return RandInt(100, 150, cnt++);
        return RandInt(150, 200, cnt++);
      } break;

      case 6: {
        return 200;
      } break;

      case 7: {
        if (magic_lv == 0) return RandInt(2, 200, cnt++);
        if (magic_lv == 1) return RandInt(200, 800, cnt++);
        if (magic_lv == 2) return RandInt(800, 1600, cnt++);
        if (magic_lv == 3) return RandInt(1600, 2400, cnt++);
        return RandInt(2400, 4000, cnt++);
      } break;

      case 8: {
        if (magic_lv == 1) return RandInt(10, 50, cnt++);
        if (magic_lv == 2) return RandInt(50, 100, cnt++);
        if (magic_lv == 3) return RandInt(100, 150, cnt++);
        return RandInt(150, 200, cnt++);
      } break;

      case 9: {
        return 200;
      } break;

      case 10: {
        if (magic_lv == 0) return RandInt(1, 5, cnt++);
        if (magic_lv == 1) return RandInt(5, 10, cnt++);
        if (magic_lv == 2) return RandInt(10, 25, cnt++);
        if (magic_lv == 3) return RandInt(25, 50, cnt++);
        return RandInt(50, 100, cnt++);
      } break;

      case 11: {
        if (magic_lv == 2) return RandInt(1, 10, cnt++);
        if (magic_lv == 3) return RandInt(10, 50, cnt++);
        return RandInt(50, 100, cnt++);
      } break;

      case 12: {
        return 200;
      } break;

      case 13: {
        if (magic_lv <= 1) return RandInt(1 + (magic_lv == 1 ? 4 : 0), 5 + (magic_lv == 1 ? 5 : 0), cnt++);
        if (magic_lv == 2) return RandInt(5, 10, cnt++);
        if (magic_lv == 3) return RandInt(10, 20, cnt++);
        return RandInt(20, 25, cnt++);
      }

      case 14: {
        return 1 + magic_lv;
      } break;

      case 15: {
        return 200;
      } break;

      case 16: {
        if (magic_lv == 2) return 1;
        if (magic_lv == 3) return 2;
        return 3;
      } break;

      case 17: {
        static const int64_t kDiscount[5] = {-5, -10, -15, -20, -25};
        return kDiscount[magic_lv];
      } break;

      case 18: {
        return 200;
      } break;
    }
    assert(0);
    return 0;
  }

  vector<int64_t> arr;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t seed;
  cin >> seed;

  Simulator sim(seed);

  Game game(seed);
  game.Smelt();
  while (game.GetAxe(0).smelt_lv < 30) {
    bool smelt = [&]() {
      int64_t luna = game.GetLuna();
      Axe axe = game.GetAxe(0);
      int64_t cost = axe.GetSmeltCost();
      return luna >= cost;
    }();

    if (smelt) {
      game.Smelt();
    } else {
      game.Mine();
    }
  }

  while (game.GetAxe(0).magic_lv < 4 || game.GetStoneNeeded(3) || game.GetStoneNeeded(4)) {
    bool rankup = [&]() {
      Axe axe = game.GetAxe(0);
      int dst = axe.magic_lv + 1;
      if (!(1 <= dst && dst <= 4) || game.GetStone(dst) <= 0) return false;

      int64_t rng_cnt = game.GetRandCount();
      return sim.Chance(kRankUpProb[dst], rng_cnt);
    }();

    auto Craft = [&](int rank) {
      if (!game.GetStoneNeeded(rank)) return false;

      int64_t luna = game.GetLuna();
      int64_t stone = game.GetStone(rank - 1);
      int64_t cost = kCraftCost[rank];
      return (stone >= 2 && luna >= cost);
    };

    if (rankup) {
      game.RankUp();
    } else if (Craft(4)) {
      game.Craft(4);
    } else if (Craft(3)) {
      game.Craft(3);
    } else {
      game.Mine();
    }
  }

  int ai = 0;
  auto ach = sim.GetAch10Events(game.GetRandCount());
  while (!game.IsDone(9)) {
    int64_t rng_cnt = game.GetRandCount();

    int na = ach.size();
    while (ai < na && ach[ai] < rng_cnt) ++ai;

    int64_t nxt = (ai < na ? ach[ai] : INT64_MAX);
    int64_t rem = nxt - rng_cnt;
    if (rem <= 9000) {
      if (rem == 0) {
        game.Enchant();
      } else if (rem % 6 == 0) {
        game.Mine();
      } else {
        bool rankup = false;
        for (int i = 1; i <= 2; i++) {
          Axe axe = game.GetAxe(i);
          int dst = axe.magic_lv + 1;
          if (!(1 <= dst && dst <= 4) || game.GetStone(dst) <= 0) continue;

          if (sim.Chance(kRankUpProb[dst], rng_cnt)) {
            game.Equip(i);
            game.RankUp();
            game.Equip(0);
            rankup = true;
            break;
          }
        }
        if (rankup) continue;

        bool smelt = false;
        for (int i = 1; i <= 2; i++) {
          int64_t luna = game.GetLuna();
          Axe axe = game.GetAxe(i);
          if (axe.smelt_lv >= 30) continue;

          int64_t cost = axe.GetSmeltCost();
          if (luna < cost) continue;
          if ((axe.smelt_lv <= 30 - i) || (i == 2 && axe.smelt_lv == 29 && !sim.Chance(axe.GetSmeltProb(), rng_cnt))) {
            game.Equip(i);
            game.Smelt();
            game.Equip(0);
            smelt = true;
            break;
          }
        }
        if (smelt) continue;

        game.Mine();
      }
    } else {
      int64_t luna = game.GetLuna();

      bool done = false;
      for (int i = 0; i < 3; i++) {
        if ((!game.IsDone(3) && sim.CanAchieve4(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt)) ||
            (!game.IsDone(4) && sim.CanAchieve5(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt)) ||
            (!game.IsDone(5) && sim.CanAchieve6(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt))) {
          if (i) game.Equip(i);
          game.Enchant();
          if (i) game.Equip(0);
          done = true;
          break;
        }
      }
      if (done) continue;

      bool rankup = false;
      for (int i = 1; i <= 2; i++) {
        Axe axe = game.GetAxe(i);
        int dst = axe.magic_lv + 1;
        if (!(1 <= dst && dst <= 4) || game.GetStone(dst) <= 0) continue;

        if (sim.Chance(kRankUpProb[dst], rng_cnt)) {
          game.Equip(i);
          game.RankUp();
          game.Equip(0);
          rankup = true;
          break;
        }
      }
      if (rankup) continue;

      bool smelt = false;
      for (int i = 1; i <= 2; i++) {
        int64_t luna = game.GetLuna();
        Axe axe = game.GetAxe(i);
        if (axe.smelt_lv >= 30) continue;

        int64_t cost = axe.GetSmeltCost();
        if (luna < cost) continue;
        if ((axe.smelt_lv <= 30 - i) || (i == 2 && axe.smelt_lv == 29 && !sim.Chance(axe.GetSmeltProb(), rng_cnt))) {
          game.Equip(i);
          game.Smelt();
          game.Equip(0);
          smelt = true;
          break;
        }
      }
      if (smelt) continue;

      game.Mine();
    }
  }

  while (!game.IsDone(3) || !game.IsDone(4) || !game.IsDone(5) || !game.IsDone(8)) {
    int64_t rng_cnt = game.GetRandCount();
    int64_t luna = game.GetLuna();

    bool done = false;
    for (int i = 0; i < 3; i++) {
      if (game.GetAxe(i).GetFinalSmeltLv() == 39) continue;

      if ((!game.IsDone(3) && sim.CanAchieve4(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt)) ||
          (!game.IsDone(4) && sim.CanAchieve5(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt)) ||
          (!game.IsDone(5) && sim.CanAchieve6(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt)) ||
          (!game.IsDone(8) && sim.CanAchieve9(game.GetAxe(i), luna, game.GetBlessLv(), rng_cnt))) {
        if (i) game.Equip(i);
        game.Enchant();
        if (i) game.Equip(0);
        done = true;
        break;
      }
    }
    if (done) continue;

    bool rankup = false;
    for (int i = 1; i <= 2; i++) {
      Axe axe = game.GetAxe(i);
      int dst = axe.magic_lv + 1;
      if (!(1 <= dst && dst <= 4) || game.GetStone(dst) <= 0) continue;

      if (sim.Chance(kRankUpProb[dst], rng_cnt)) {
        game.Equip(i);
        game.RankUp();
        game.Equip(0);
        rankup = true;
        break;
      }
    }
    if (rankup) continue;

    bool smelt = false;
    for (int i = 1; i <= 2; i++) {
      int64_t luna = game.GetLuna();
      Axe axe = game.GetAxe(i);
      if (axe.smelt_lv >= 30) continue;

      int64_t cost = axe.GetSmeltCost();
      if (luna < cost) continue;
      if ((axe.smelt_lv <= 30 - i) || (i == 2 && axe.smelt_lv == 29 && !sim.Chance(axe.GetSmeltProb(), rng_cnt))) {
        game.Equip(i);
        game.Smelt();
        game.Equip(0);
        smelt = true;
        break;
      }
    }
    if (smelt) continue;

    game.Mine();
  }

  while (!game.IsDone()) {
    int64_t rng_cnt = game.GetRandCount();

    bool rankup = false;
    for (int i = 1; i <= 2; i++) {
      Axe axe = game.GetAxe(i);
      int dst = axe.magic_lv + 1;
      if (!(1 <= dst && dst <= 4) || game.GetStone(dst) <= 0) continue;

      if (sim.Chance(kRankUpProb[dst], rng_cnt)) {
        game.Equip(i);
        game.RankUp();
        game.Equip(0);
        rankup = true;
        break;
      }
    }
    if (rankup) continue;

    game.Mine();
  }
  game.Exit();

  // #ifdef DEBUG
  //   cerr << "Seed: " << seed << "\n";
  //   cerr << "Result: " << (game.IsDone() ? "AC\n" : "WA\n");
  //   for (int i = 0; i < 10; i++) {
  //     cerr << i + 1 << ": " << game.IsDone(i) << "\n";
  //   }
  //   cerr << "Query: " << (game.GetRemQuries() - 180000) << "\n";
  //   cerr << "Luna: " << game.GetLuna() << "\n";
  //   cerr << "Stone: ";
  //   for (int i = 0; i < 5; i++) {
  //     cerr << game.GetStone(i) << " ";
  //   }
  //   cerr << "\n";
  //   cerr << "Axe: ";
  //   for (int i = 0; i < 3; i++) cerr << game.GetAxe(i).GetFinalSmeltLv() << "|" << game.GetAxe(i).magic_lv << " ";
  //   cerr << "\n\n";
  // #endif

  return 0;
}