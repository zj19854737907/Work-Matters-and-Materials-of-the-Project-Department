#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string category;

    // ���캯�������ڴ��� Contact ����
    Contact(const std::string& n, const std::string& phone, const std::string& cat = "δ����")
        : name(n), phoneNumber(phone), category(cat) {}

    // Ĭ�Ϲ��캯��
    Contact() = default;
};

class ContactManager {
private:
    std::vector<Contact> contacts; // �洢��ϵ�˵�����

public:
    // ��ȡ�û������Դ��� Contact ����
    Contact getUserInputForContact() {
        std::string name, phone, category;
        std::cout << "��������ϵ������: ";
        std::cin >> name;
        std::cout << "��������ϵ�˵绰����: ";
        std::cin >> phone;
        std::cout << "��������ϵ�˷���: ";
        std::cin >> category;

        return Contact(name, phone, category);
    }

    // �����ϵ�˵�����
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // ɾ����ϵ��
    void deleteContact(const std::string& name) {
        // ʹ�� remove_if �� erase ɾ��������������ϵ��
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        contacts.erase(it, contacts.end());
        std::cout << "��ϵ����ɾ����" << std::endl;
    }

    // ������������ϵ��
    Contact searchContact(const std::string& name) {
        // ʹ�� find ������ϵ��
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });
        return (it != contacts.end()) ? *it : Contact(); // δ�ҵ�ʱ���ؿ� Contact ����
    }

    // ���绰����������ϵ��
    Contact searchContact(const int phoneNumber) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&phoneNumber](const Contact& c) {
            return std::stoi(c.phoneNumber) == phoneNumber;
        });
        return (it != contacts.end()) ? *it : Contact(); // δ�ҵ�ʱ���ؿ� Contact ����
    }

    // ������������ϵ��
    std::vector<Contact> searchContactByCategory(const std::string& category) {
        std::vector<Contact> result;

        // ʹ�� std::copy_if ��������������ϵ�˸��Ƶ����������
        std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(result), [&category](const Contact& c) {
            return c.category == category;
        });

        // ��ʾ������������ϵ��
        if (!result.empty()) {
            std::cout << "�ҵ�������ϵ�ˣ�" << std::endl;
            for (const auto& contact : result) {
                std::cout << "����: " << contact.name << ", �绰: " << contact.phoneNumber << ", ����: " << contact.category << std::endl;
            }
        } else {
            std::cout << "δ�ҵ��÷����µ���ϵ�ˡ�" << std::endl;
        }

        return result;
    }

    // �༭��ϵ����Ϣ
    void editContact(const std::string& name, const std::string& newPhoneNumber) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        if (it != contacts.end()) {
            it->phoneNumber = newPhoneNumber;
            std::cout << "��ϵ����Ϣ�ѱ༭��" << std::endl;
        } else {
            std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
        }
    }
};

int main() {
    ContactManager contactManager;

    int choice;
    do {
        // ��ʾ�˵�
        std::cout << "1. �����ϵ��\n";
        std::cout << "2. ɾ����ϵ��\n";
        std::cout << "3. ������ϵ�ˣ�ͨ��������\n";
        std::cout << "4. ������ϵ�ˣ�ͨ���绰���룩\n";
        std::cout << "5. ������ϵ�ˣ�ͨ�����ࣩ\n";
        std::cout << "6. �༭��ϵ����Ϣ\n";
        std::cout << "7. �˳�\n";
        std::cout << "��ѡ����: ";
        std::cin >> choice;

        // �����û�ѡ��ִ����Ӧ����
        switch (choice) {
            case 1: {
                Contact newContact = contactManager.getUserInputForContact();
                contactManager.addContact(newContact);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "������Ҫɾ������ϵ������: ";
                std::cin >> name;
                contactManager.deleteContact(name);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "������Ҫ��������ϵ������: ";
                std::cin >> name;
                Contact foundContact = contactManager.searchContact(name);
                if (!foundContact.name.empty()) {
                    std::cout << "�ҵ���ϵ��: " << foundContact.name << ", �绰: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 4: {
                int phoneNumber;
                std::cout << "������Ҫ��������ϵ�˵绰����: ";
                std::cin >> phoneNumber;
                Contact foundContact = contactManager.searchContact(phoneNumber);
                if (!foundContact.name.empty()) {
                    std::cout << "�ҵ���ϵ��: " << foundContact.name << ", �绰: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 5: {
                std::string category;
                std::cout << "������Ҫ��������ϵ�˷���: ";
                std::cin >> category;
                contactManager.searchContactByCategory(category);
                break;
            }
            case 6: {
                std::string name, newPhone;
                std::cout << "������Ҫ�༭����ϵ������: ";
                std::cin >> name;
                std::cout << "�������µĵ绰����: ";
                std::cin >> newPhone;
                contactManager.editContact(name, newPhone);
                break;
            }
            case 7: {
                std::cout << "��лʹ�ã��ټ���" << std::endl;
                break;
            }
            default:
                std::cout << "��Ч��ѡ�������ѡ��" << std::endl;
        }
    } while (choice != 7);

    return 0;
}


