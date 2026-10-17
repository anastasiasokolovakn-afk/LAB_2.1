#include <iostream>
#include <Windows.h> 
#include "Product.h"

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== 1. Ð²ÇÍ² ÑÏÎÑÎÁÈ ÑÒÂÎÐÅÍÍß ÎÁ'ªÊÒ²Â ===" << endl;
    Product p1;
    cout << "p1 (çà çàìîâ÷óâàííÿì): " << p1 << endl;

    Product p2(250, 0.5);
    cout << "p2 (ç ïàðàìåòðàìè): " << p2 << endl;

    Product p3(p2);
    cout << "p3 (êîï³ÿ p2): " << p3 << endl;

    Product* pPtr = new Product(400, 1.2);
    cout << "pPtr (äèíàì³÷íèé îá'ºêò): " << *pPtr << endl;

    cout << "\n=== 2. ÑÒÂÎÐÅÍÍß ÌÀÑÈÂ²Â ÎÁ'ªÊÒ²Â ===" << endl;
    Product staticArr[2] = { Product(100, 0.2), Product(180, 0.7) };
    cout << "Ñòàòè÷íèé ìàñèâ:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "  arr[" << i << "]: " << staticArr[i] << endl;
    }

    Product* dynamicArr = new Product[2];
    dynamicArr[0] = Product(320, 1.0);
    dynamicArr[1] = Product(50, 2.0);
    cout << "Äèíàì³÷íèé ìàñèâ:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "  dynamicArr[" << i << "]: " << dynamicArr[i] << endl;
    }
    delete[] dynamicArr; 

    cout << "\n=== 3. ÄÅÌÎÍÑÒÐÀÖ²ß ÂÑ²Õ ÌÅÒÎÄ²Â ===" << endl;
    cout << "Ãåòåðè äëÿ p2: first = " << p2.GetFirst()
        << ", second = " << p2.GetSecond() << endl;

    p2.SetFirst(300);
    p2.SetSecond(0.8);
    cout << "Ï³ñëÿ óñï³øíèõ ñåòòåð³â p2: " << p2 << endl;

    if (!p2.SetFirst(-50)) {
        cout << "Ñåòòåð â³äõèëèâ íåêîðåêòíå çíà÷åííÿ êàëîð³éíîñò³ (-50)" << endl;
    }

    cout << "Çàãàëüíà êàëîð³éí³ñòü p2 (ìåòîä power): " << p2.power() << " êêàë" << endl;

    p1 = p2;
    cout << "Ï³ñëÿ ïðèñâîºííÿ p1 = p2, p1: " << p1 << endl;

    string strRepresentation = string(p1);
    cout << "Ðÿäêîâå ïðåäñòàâëåííÿ p1: " << strRepresentation << endl;

    cout << "\n=== 4. ÏÅÐÅÂÀÍÒÀÆÅÍ² ÎÏÅÐÀÒÎÐÈ ²ÍÊÐÅÌÅÍÒÓ ÒÀ ÄÅÊÐÅÌÅÍÒÓ ===" << endl;
    cout << "Ïî÷àòêîâèé p1: " << p1 << endl;
    ++p1;
    cout << "Ïðåô³êñíèé ++p1 (êàëîð³¿ +1): " << p1 << endl;
    --p1;
    cout << "Ïðåô³êñíèé --p1 (êàëîð³¿ -1): " << p1 << endl;
    p1++;
    cout << "Ïîñòô³êñíèé p1++ (âàãà +0.1): " << p1 << endl;
    p1--;
    cout << "Ïîñòô³êñíèé p1-- (âàãà -0.1): " << p1 << endl;

    cout << "\n=== 5. ÂÂÅÄÅÍÍß ÎÁ'ªÊÒÀ Ç ÊËÀÂ²ÀÒÓÐÈ (operator>>) ===" << endl;
    cin >> p1;
    cout << "Âè ââåëè p1: " << p1 << endl;

    cout << "\n=== 6. ÐÎÇÌ²Ð ÊËÀÑÓ ===" << endl;
    cout << "Ïîòî÷íèé ðîçì³ð êëàñó Product: " << sizeof(Product) << " áàéò³â" << endl;

    delete pPtr;
}