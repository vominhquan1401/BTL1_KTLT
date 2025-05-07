#include "knight.h"

const int Bowser = 99;
const int MADBEAR = 1;
const int BANDIT = 2;
const int LORDLUPIN = 3;
const int ELF = 4;
const int TROLL = 5;
const int SHAMAN = 6;
const int VAJSH = 7;
const int MushMario = 11;
const int MushFib = 12;
const int REMEDY = 15;
const int MAIDENKISS = 16;
const int PHOENIXDOWN = 17;
const int MERLIN = 18;
const int ASCLEPIUS = 19;

int LEVELO(int count) {
    count++;
    int i = count;
    int b = 0;
    b = i % 10;
    return (i > 6 ? (b > 5 ? b : 5) : b);
}

bool primeNumber(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

string HERO(int maxhp) {
    if (primeNumber(maxhp))
        return "lancelot";
    else if (maxhp == 999)
        return "arthur";
    else
        return "HiepSiBanTron";
}

void MUSHMARIO(int &HP, int maxhp, int level, int &phoenix) {
    int n1 = ((level + phoenix) % 5 + 1) * 3;
    int s1 = 0;
    if (n1 == 0)
        return;
    for (int i = 99; i >= 0; i = i - 2) {
        s1 += i;
        n1--;
        if (n1 == 0) {
            break;
        }
    }
    HP = HP + s1 % 100;//sau khi đã cộng máu
    if (HP > maxhp)
    {
        HP = maxhp;
    } // đưa về lượng máu lớn nhất
    else {
        for (int i = HP+1; i < maxhp+1; i++) {
            if (primeNumber(i)) {
                HP = i;
                return;
            }
            else {
                HP = maxhp;
            }
        }
    }
}//DONE

int Shaman(int &HP,int maxhp, int &level, int &Remedy, int &phoenix, int ThuTuSuKien, int minisize, int frog) {
    int levelShaman = LEVELO(ThuTuSuKien);
    if (minisize > 0 || frog > 0 || level==levelShaman)
    {
        return minisize;
    }
    if (level > levelShaman) {
        level += 2;
        if (level > 10)
            level = 10;
        return -1;
    }
    else if (level < levelShaman)
    {   
        int temp = HP % 5;
        HP /= 5;
        if (HP == 0) {
            HP = 1;
        }

        if (Remedy > 0) {
            HP = HP * 5 + temp;
            Remedy--;
            if (HP > maxhp)
            {
                HP = maxhp;
            }
            return -1;
        }
    }

    return 4;
}

//fibonacci_mush
bool isFibonacci(int n) {
    int a = 0, b = 1, c;
    while (b < n) {
        c = a + b;
        a = b;
        b = c;
    }
    return (b == n);
}

void fibo_mush(int& HP) {
    int temp = 0;
    for (int i = HP-1; i >= 0; i--) {
        if (isFibonacci(i)) {
            temp = i;
            break;
        }
    }
    HP = temp;
}
//end fibonacci


int BaseDamage(int event1To5)
{
    if (event1To5 == MADBEAR)
        return 10;
    else if (event1To5 == BANDIT)
        return 15;
    else if (event1To5 == LORDLUPIN)
        return 45;
    else if (event1To5 == ELF)
        return 75;
    else if (event1To5 == TROLL)
        return 95;
    return 0;
}

int Damage(int sukien, int count,int &level) {
    int levelo = LEVELO(count);
    if (level > levelo) {
        level += 1;
        if (level > 10)
            level = 10;
        return 0;
    }
    else if (level == levelo) {
        return 0;
    }
    int baseDamage = BaseDamage(sukien);
    return  baseDamage*levelo;
}

bool CheckHP(int &HP, int maxhp, int &phoenixdown,int &minisize,int &frog,int &level,int templevel) {
    if (HP <= 0) {
        if (phoenixdown > 0)
        {
            phoenixdown--;
            HP = maxhp;
            if (minisize > 0) {
                minisize = -1;
                HP *= 5;
                if (HP > maxhp)
                    HP = maxhp;
            }if (minisize > 0) {
                frog = -1;
                level = templevel;
            }
            return true;
        }
        return false;
    }
    if (HP > maxhp) {
        HP = maxhp;
    }
    return true;
}

int Vajsh(int &HP, int &level,int templevel, int &maidenkiss, int &phoenix, int ThuTuSuKien, int minisize ,int frog) {
    int levelVajsh = LEVELO(ThuTuSuKien);
    if (minisize > 0 || frog > 0 || level==levelVajsh)
    {
        return frog;
    }
    if (level > levelVajsh) {
        level += 2;
        if (level > 10)
            level = 10;
        return -1;
    }
    else if (level < levelVajsh) {
        level -= 1;
        if (level < 1) {
            level = 1;
        }
        if (maidenkiss > 0) {
            level = templevel;
            maidenkiss--;
            return -1;
        }
        return 4;
    }
    return frog;
}
void Aclepius(string file_aclepius_pack, int& HP, int maxhp,int templevel, int &level, int& remedy, int& maidenkiss, int& phoenixdown, int& minisize, int& frog) {
    ifstream file_input(file_aclepius_pack);
    int r1,c1;
    file_input >> r1;
    file_input >> c1;
 
    int medicines[100][100];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            file_input >> medicines[i][j];
        }
    }
    file_input.close();
    int count_receive_pack = 0;
    for (int i = 0; i < r1; i++) {
        count_receive_pack = 0;
        for (int j = 0; j < c1; j++) 
        {
            if (medicines[i][j] == 16 || medicines[i][j] == 17 || medicines[i][j] == 18) 
            {
                if (medicines[i][j] == 16) {
                    remedy++;  
                    if (remedy > 99) {
                        remedy = 99;
                    }
                    if (minisize > 0) 
                    {
                        minisize = -1;
                        remedy--;
                        HP *= 5;
                        if (HP > maxhp) {
                            HP = maxhp;
                        }
                    } 
                    count_receive_pack++;
                }
                if (medicines[i][j] == 17) {
                    maidenkiss++; 
                    if (maidenkiss >= 99) {
                        maidenkiss = 99;
                    }
                    if (frog > 0) {
                        frog = -1;
                        maidenkiss--;
                        level = templevel;
                    }
                    count_receive_pack++;
                }
                if (medicines[i][j] == 18) {
                    phoenixdown++; 
                    if (phoenixdown > 99) {
                        phoenixdown = 99;
                    }
                    count_receive_pack++;
                    }
                }
            if (count_receive_pack == 3) 
            {
            count_receive_pack = 0;
            break;
            }
            }
    }

}

void Merlin(string file_merlin_pack, int &HP, int max_hp) {
    ifstream file(file_merlin_pack);
    int dem1 = 0;
    int dem2 = 0;
    int dem3 = 0;
    int n9;
    file >> n9;
    file.ignore(); // bỏ qua ký tự '\n'
    string items[1000];
    for (int i = 0; i < n9; i++) {
        getline(file, items[i]);
        if (items[i].find("merlin") != string::npos|| items[i].find("Merlin") != string::npos) {
            dem1++;
        }
        // chuyển các ký tự trong items[i] thành chữ thường
        for (int j = 0; j < items[i].length(); j++) {
            if (items[i][j] >= 'A' && items[i][j] <= 'Z') {
                items[i][j] = items[i][j] + ('a' - 'A');
            }
        }
    }
    file.close();

    for (int i = 0; i < n9; i++) {
        int count = 0;
        for (int j = 0; j < items[i].length(); j++) {
            if (items[i][j] == 'm' || items[i][j] == 'e' || items[i][j] == 'r' ||
                items[i][j] == 'l' || items[i][j] == 'i' || items[i][j] == 'n') {
                count++;
            }
        }
        if (count >= 6) {
            if (items[i].find("merlin") != string::npos) {
                dem2++;
            }
            else {
                dem3++;
            }
        }
    }
    if (dem1 == 0) dem2 = 0;
    HP = HP + 3 * (dem1)+2 * (dem3 + dem2 - dem1);
    if (HP > max_hp) {
        HP = max_hp;
    }
}
void MushG(char type, int mushG[], int n2, int &HP,int maxhp,int &phoenixdown,int &minisize,int &rescue,int &frog,int &level,int templevel) {
    int *mush = new int[n2]; // create a copy of the array
    for (int i = 0; i < n2; i++)
    {
        mush[i] = mushG[i];
    }
    if (type == '1') {
        {
            int max = mush[0];
            int maxi = 0;
            int min = mush[0];
            int mini = 0;
            for (int i = 1; i < n2; i++) {
                if (max <= mush[i])
                {
                    max = mush[i];
                    maxi = i;
                }
                if (min >= mush[i])
                {
                    min = mush[i];
                    mini = i;
                }
            }
                 HP -= (maxi + mini);
            if (CheckHP(HP, maxhp, phoenixdown, minisize,frog,level,templevel)) {
                rescue = -1;
            }
            else {
                rescue = 0;
                return;
            }
               
        }
    }
    if (type == '2')
    {
            int mtx = -2;
            int mti = -3;
            int maxi = 0;
            bool iscreasing = true;
            bool isdecreasing = true;
            for (int i = 1; i < n2; i++) {
                if (mush[i] > mush[maxi]) {
                    maxi = i;
                }
            }
            if (maxi == 0 ) {
                for (int i = 0; i < n2 - 1; i++) {
                        if (mush[i] <= mush[i + 1]) {
                            isdecreasing = false;
                            break;
                        }
                 }                    
                if (isdecreasing) {
                    mtx = mush[maxi];
                    mti = maxi;
                }          
            } else if (maxi == n2 - 1) {
                for (int i = 0; i < maxi; i++) {
                    if (mush[i] >= mush[i + 1]) {
                        iscreasing = false;
                        break;
                    }
                }
                if (iscreasing) {
                    mtx = mush[maxi];
                    mti = maxi;
                } 
            } else {
                for (int i = 0; i < maxi; i++) {
                    if (mush[i] >= mush[i + 1]) {
                        iscreasing = false;
                        break;
                    }
                }
                for (int i = maxi; i < n2-1; i++) {
                    if (mush[i] <= mush[i + 1]) {
                        isdecreasing = false;
                        break;
                    }
                }
                if (iscreasing && isdecreasing) {
                    mtx = mush[maxi];
                    mti = maxi;
                }            
            }    
            if (!iscreasing || !isdecreasing) {
                mtx = -2;
                mti = -3;
            }
              HP -= (mtx + mti); 
            if (CheckHP(HP, maxhp, phoenixdown, minisize,frog,level,templevel)) {
                rescue = -1;
            }
            else {
                rescue = 0;
                return;
            }
    }
    if (type == '3')
    {
        int maxi2 = 0;
        int mini2 = 0;
        for (int i = 0; i < n2; i++) {
            if (mush[i] < 0) {
                mush[i] = -mush[i];
            }
            mush[i] = (17 * mush[i] + 9) % 257;
        }
        for (int i = 0; i < n2; i++) {
            if (mush[i] > mush[maxi2])
            {
                maxi2 = i;
            }
            if (mush[i] < mush[mini2]) {
                mini2 = i;
            }
        }
            HP -= (maxi2 + mini2);
        if (CheckHP(HP, maxhp, phoenixdown, minisize,frog,level,templevel)) {
            rescue = -1;
        }
        else {
            rescue = 0;
            return;
        }
    }
    if (type == '4')
    {   
            int count = 0;
            int max2_3x = -5; 
            int max2_3i = -7;
            int max = INT8_MIN;
            int maxi = 0;
        if (n2 > 2) {
        for (int i = 0; i < n2; i++) {
            if (mush[i] < 0) {
                mush[i] = -1 * mush[i];
            }
            mush[i] = (17 * mush[i] + 9) % 257;
        }   
            for (int i = 0; i < 3; i++) {
                if (max == mush[i]) {
                    count++;
                }
                if (max < mush[i])
                {
                    max = mush[i];
                    maxi = i;
                }
            }
                if (maxi == 0) {
                    if (count == 1) {
                        if (mush[1] > mush[2]) {
                            max2_3x = mush[2];
                            max2_3i = 2;
                        }
                        else {
                            max2_3x = mush[1];
                            max2_3i = 1;
                        }
                    }
                    else if (mush[1] > mush[2]) {
                        max2_3x = mush[1];
                        max2_3i = 1;
                    }
                    else if (mush[1] < mush[2]) {
                        max2_3x = mush[2];
                        max2_3i = 2;
                    }
                    else {
                        max2_3x = mush[1];
                        max2_3i = 1;
                    }
                } 
                if (maxi == 1) {
                    if (count==1) {
                        if (mush[2] = mush[maxi]) {
                            max2_3x = mush[0];
                            max2_3i = 0;
                        }
                        else {
                            max2_3x = mush[2];
                            max2_3i = 2;
                        }
                    }
                    else if (mush[2] > mush[0]) {
                        max2_3x = mush[2];
                        max2_3i = 2;
                    }
                    else if (mush[2] < mush[0]) {
                        max2_3x = mush[0];
                        max2_3i = 0;
                    }
                    else {
                        max2_3x = mush[0];
                        max2_3i = 0;
                    }
                }
                if (maxi == 2) {
                    if (count==1 && mush[0]!=mush[1]) {
                        if (mush[0] > mush[1]) {
                            max2_3x = mush[1];
                            max2_3i = 1;
                        }
                        else {
                            max2_3x = mush[0];
                            max2_3i = 0;
                        }
                    }
                    else if (mush[0] > mush[1]) {
                        max2_3x = mush[0];
                        max2_3i = 0;
                    }
                    else if (mush[0] < mush[1]) {
                        max2_3x = mush[1];
                        max2_3i = 1;
                    }
                    else {
                        max2_3x = mush[0];
                        max2_3i = 0;
                    }
                }
                if (count == 2) {
                    max2_3x = -5;
                    max2_3i = -7;
                }
        }
        else {
            max2_3x = -5;
            max2_3i = -7;
        }
            HP -= (max2_3x + max2_3i);
            if (CheckHP(HP, maxhp, phoenixdown, minisize,frog,level,templevel)) {
            rescue = -1;
        }
        else {
            rescue = 0;
            return;
        }
    }
    delete[]mush;
}

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    // Init value
    rescue = -1;
    int sukien;
    int minisize=0;
    int frog=0;
    int n9;
    int templevel = level;
    int events[1000];
    int num_events = 0;
    int Aclepius_count = 0;
    int Merlin_count = 0;
    string line;
    string file_mush_ghost;
    string file_asclepius_pack;
    string file_merlin_pack;
    string file_merlin;
    ifstream input_file(file_input);
    if (input_file.is_open())
    {
        input_file >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
        string line;
        getline(input_file, line); 
        getline(input_file, line); 
        istringstream iss(line);
        int event;
        while (iss >> event)
        {
            events[num_events++] = event;
        }
        getline(input_file, line); 
        istringstream iss2(line);
        getline(iss2, file_mush_ghost,',');
        getline(iss2, file_asclepius_pack,',');
        getline(iss2, file_merlin_pack);
        input_file.close();
    }
    int MAXHP = HP;
    if (HP > 999) {
        HP = 999;
    }
    for(int count=0;count<num_events;count++){
        sukien = events[count];
        switch (sukien){
        case 0:
            display(HP, level, remedy, maidenkiss, phoenixdown, 1);
            return;
        case Bowser:
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                if (level >= 8)
                    level = 10;
                else {
                    rescue = 0;
                }                  
            }
            else {
                if (level != 10) {
                    rescue = 0;
                }
            }
        case MADBEAR:
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 1;
                if (level > 10) {
                    level = 10;
                }
                break;
            }
            HP -= Damage(MADBEAR, count,level);
            if (!CheckHP(HP, MAXHP, phoenixdown,minisize,frog,level,templevel))
                rescue = 0;
            break;
        case BANDIT:
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 1;
                if (level > 10) {
                    level = 10;
                }
                break;
            }            
            HP -= Damage(BANDIT, count,level);
            if (!CheckHP(HP, MAXHP, phoenixdown,minisize,frog,level,templevel))
                rescue = 0;
            break;
        case LORDLUPIN:
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 1;
                if (level > 10) {
                    level = 10;
                }
                break;
            }                     
            HP -= Damage(LORDLUPIN, count,level);
            if (!CheckHP(HP, MAXHP, phoenixdown,minisize,frog,level,templevel))
                rescue = 0;  
            break;
        case ELF:
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 1;
                if (level > 10) {
                    level = 10;
                }
                break;
            }
            HP -= Damage(ELF, count,level);
            if (!CheckHP(HP, MAXHP, phoenixdown,minisize,frog,level,templevel))
                rescue = 0;
            break;
        case TROLL:
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 1;
                if (level > 10) {
                    level = 10;
                }
                break;
            }           
            HP -= Damage(TROLL, count,level);
            if (!CheckHP(HP, MAXHP, phoenixdown,minisize,frog,level,templevel))
                rescue = 0;
            break;
        // special monsters
        case SHAMAN:
        {   
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 2;
                if (level > 10) {
                    level = 10;
                }
                break;
            }  
            minisize = Shaman(HP, MAXHP, level, remedy, phoenixdown, count, minisize, frog);
        }
            break;
        case VAJSH:
        {   
            templevel = level;
            if (HERO(MAXHP) == "arthur" || HERO(MAXHP) == "lancelot") {
                level += 2;
                if (level > 10) {
                    level = 10;
                }
                break;
            }
            frog = Vajsh(HP, level, templevel, maidenkiss, phoenixdown, count, minisize, frog);
        }
            break;
        case MushMario:
            MUSHMARIO(HP, MAXHP, level, phoenixdown);
            break;
        case MushFib:
            fibo_mush(HP);
            break;
        case MERLIN:
            if (Merlin_count == 0)
                Merlin_count++;
            else
                break;
            Merlin(file_merlin_pack,HP,MAXHP);
            break;
        case ASCLEPIUS:
            if (Aclepius_count == 0)
                Aclepius_count++;
            else
                break;
            Aclepius(file_asclepius_pack,HP,MAXHP,templevel,level, remedy, maidenkiss, phoenixdown,minisize,frog);
            break;
        case REMEDY:
            remedy++; 
            if (remedy > 99) {
                remedy = 99;
            }
            if (minisize > 0) {
                minisize = 0;
                remedy--;
                HP *= 5;
                if (HP > 999) {
                    HP = 999;
                }
            }
            break;
        case MAIDENKISS:
            maidenkiss++;
            if (maidenkiss > 99) {
                maidenkiss = 99;
            }
            if (frog > 0) {
                frog = 0;
                maidenkiss--;
                level = templevel;
            }
            break;
        case PHOENIXDOWN:
            phoenixdown++; 
            if (phoenixdown > 99) {
                phoenixdown = 99;
            }
            if (frog > 0 ) {
                frog = 0;
                phoenixdown--;
            }
            if (minisize > 0) {
                minisize = 0;
                phoenixdown--;
            }
            break;
        default://mushghost
        {
            ifstream file1(file_mush_ghost);
            int n2;
            file1 >> n2;
            file1.ignore();
            int mush[1000];
            string line;
            getline(file1, line);
            getline(file1, line);
            stringstream ss(line);
            for (int i = 0; i < n2; i++)
            {
                string number_str;
                getline(ss, number_str, ','); // read the next number as a string, using comma as delimiter
                mush[i] = stoi(number_str);      // convert the string to integer and store in the array
            }
            file1.close();

            string mush_ghost = to_string(sukien).substr(2);
            for (char c : mush_ghost) {
                MushG(c, mush, n2, HP,MAXHP,phoenixdown,minisize,rescue,frog,level,templevel);
                if (rescue == 0) {
                    break;
                }
            }
        }
            break;
        }
        minisize--;
        if (minisize == 0) {
            if (HP > 0) {
            HP *= 5;
            if (HP > MAXHP)
                HP = MAXHP;
            }
        }
        frog--;
        if (frog == 0) {
            if (HP > 0) {
            level =templevel;
            }
        }

        if (rescue == 0) {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            return;
        }
         else if (rescue == 1) {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            return;
        }
        if (count < num_events - 1) {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
    }
    rescue = 1;
    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    return;
}
