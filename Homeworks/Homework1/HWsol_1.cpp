#include<iostream>
using namespace std;

const short Blagoevgrad = 44;
const short Burgas = 94;
const short Varna = 140;
const short VTurnovo = 170;
const short Vidin = 184;
const short Vraca = 218;
const short Gabrovo = 234;
const short Kurdjali = 282;
const short Kjustendjul = 302;
const short Love4 = 320;
const short Montana = 342;
const short Pazardjik = 378;
const short Pernik = 396;
const short Pleven = 436;
const short Plovdiv = 502;
const short Razgrad = 528;
const short Ruse = 556;
const short Silistra = 576;
const short Sliven = 602;
const short Smolqn = 624;
const short SofiaGrad = 722;
const short SofiaOkrug = 752;
const short StaraZagora = 790;
const short Dobri4 = 822;
const short Turgovi6te = 844;
const short Haskovo = 872;
const short Shumen = 904;
const short Yambol = 926;

int main()
{
    short e1,e2,e3,e4,e5,e6,e7,e8,e9,e10;
    long long egn;
    cin>>egn;

    /// Getting all the digits from the EGN (works even with zeros in front)
    e10=egn%10; egn/=10;
    e9=egn%10; egn/=10;
    e8=egn%10; egn/=10;
    e7=egn%10; egn/=10;
    e6=egn%10; egn/=10;
    e5=egn%10; egn/=10;
    e4=egn%10; egn/=10;
    e3=egn%10; egn/=10;
    e2=egn%10; egn/=10;
    e1=egn;

    /// Validation
    if(e10!=((e1*2+e2*4+e3*8+e4*16+e5*32+e6*64+e7*128+e8*256+e9*512)%11)%10)
    {
        cout<<"Invalid EGN!"<<endl;
        return 0;
    }

    /// Printing the EGN (this way, it works even with zeros in front)
    cout<<e1<<e2<<e3<<e4<<e5<<e6<<e7<<e8<<e9<<e10<<" is the EGN of a ";

    /// Printing woman or man
    if(e9&1) ///same as e9%21=0
    {
        cout<<"wo";
    }
    cout<<"man, born on ";

    /// Printing the date
    cout<<e5<<e6<<'.'<<e3%2<<e4<<'.';
    if(e3<2)cout<<19;
    else if(e3<4)cout<<18;
    else cout<<20;
    cout<<e1<<e2<<" in ";

    /// Getting and printing the region
    int reg=e7*100+e8*10+e9;
    if(reg<Blagoevgrad)cout<<"Blagoevgrad";
    else if(reg<Burgas)cout<<"Burgas";
    else if(reg<Varna)cout<<"Varna";
    else if(reg<VTurnovo)cout<<"Veliko Turnovo";
    else if(reg<Vidin)cout<<"Vidin";
    else if(reg<Vraca)cout<<"Vratsa";
    else if(reg<Gabrovo)cout<<"Gabrovo";
    else if(reg<Kurdjali)cout<<"Kurdzhali";
    else if(reg<Kjustendjul)cout<<"Kyustendyul";
    else if(reg<Love4)cout<<"Lovech";
    else if(reg<Montana)cout<<"Montana";
    else if(reg<Pazardjik)cout<<"Pazardzhik";
    else if(reg<Pernik)cout<<"Pernik";
    else if(reg<Pleven)cout<<"Pleven";
    else if(reg<Plovdiv)cout<<"Plovdiv";
    else if(reg<Razgrad)cout<<"Razgrad";
    else if(reg<Ruse)cout<<"Ruse";
    else if(reg<Silistra)cout<<"Silistra";
    else if(reg<Sliven)cout<<"Sliven";
    else if(reg<Smolqn)cout<<"Smolyan";
    else if(reg<SofiaGrad)cout<<"Sofia (city)";
    else if(reg<SofiaOkrug)cout<<"Sofia";
    else if(reg<StaraZagora)cout<<"Stara Zagora";
    else if(reg<Dobri4)cout<<"Dobritch";
    else if(reg<Turgovi6te)cout<<"Turgovishte";
    else if(reg<Haskovo)cout<<"Haskovo";
    else if(reg<Shumen)cout<<"Shumen";
    else if(reg<Yambol)cout<<"Yambol";
    else cout<<"Unknown";
    cout<<" region, having ";

    /// Printing number of boys/girls born before the entered EGN
    if(reg<Blagoevgrad)cout<<reg/2;
    else if(reg<Burgas)cout<<(reg-Blagoevgrad)/2;
    else if(reg<Varna)cout<<(reg-Burgas)/2;
    else if(reg<VTurnovo)cout<<(reg-Varna)/2;
    else if(reg<Vidin)cout<<(reg-VTurnovo)/2;
    else if(reg<Vraca)cout<<(reg-Vidin)/2;
    else if(reg<Gabrovo)cout<<(reg-Vraca)/2;
    else if(reg<Kurdjali)cout<<(reg-Gabrovo)/2;
    else if(reg<Kjustendjul)cout<<(reg-Kurdjali)/2;
    else if(reg<Love4)cout<<(reg-Kjustendjul)/2;
    else if(reg<Montana)cout<<(reg-Love4)/2;
    else if(reg<Pazardjik)cout<<(reg-Montana)/2;
    else if(reg<Pernik)cout<<(reg-Pazardjik)/2;
    else if(reg<Pleven)cout<<(reg-Pernik)/2;
    else if(reg<Plovdiv)cout<<(reg-Pleven)/2;
    else if(reg<Razgrad)cout<<(reg-Plovdiv)/2;
    else if(reg<Ruse)cout<<(reg-Razgrad)/2;
    else if(reg<Silistra)cout<<(reg-Ruse)/2;
    else if(reg<Sliven)cout<<(reg-Silistra)/2;
    else if(reg<Smolqn)cout<<(reg-Sliven)/2;
    else if(reg<SofiaGrad)cout<<(reg-Smolqn)/2;
    else if(reg<SofiaOkrug)cout<<(reg-SofiaGrad)/2;
    else if(reg<StaraZagora)cout<<(reg-SofiaOkrug)/2;
    else if(reg<Dobri4)cout<<(reg-StaraZagora)/2;
    else if(reg<Turgovi6te)cout<<(reg-Dobri4)/2;
    else if(reg<Haskovo)cout<<(reg-Turgovi6te)/2;
    else if(reg<Shumen)cout<<(reg-Haskovo)/2;
    else if(reg<Yambol)cout<<(reg-Shumen)/2;
    else cout<<(reg-Yambol)/2;
    if(e9&1) cout<<" girl(s) being born before her";
    else cout<<" boy(s) being born before him";
    cout<<" in that day.";
    return 0;
}
