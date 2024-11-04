#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
    private:
        node *head, *tail;

    public:
        list() {
            head = NULL;
            tail = NULL;
        }

        void createnode(int value) {
            node *temp = new node;
            temp->data = value;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        void display() {
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }

        void insert_start(int value) {
            node *temp = new node;
            temp->data = value;
            temp->next = head;
            head = temp;
        }

        void insert_position(int pos, int value) {
            node *pre = new node;
            node *cur = head;
            node *temp = new node;
            for (int i = 1; i < pos; i++) {
                pre = cur;
                cur = cur->next;
            }
            temp->data = value;
            pre->next = temp;
            temp->next = cur;
        }

        void delete_first() {
            node *temp = head;
            head = head->next;
            delete temp;
        }

        void delete_last() {
            node *current = head;
            node *previous = NULL;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            tail = previous;
            if (previous != NULL)
                previous->next = NULL;
            delete current;
        }

        void delete_position(int pos) {
            node *current = head;
            node *previous = NULL;
            for (int i = 1; i < pos; i++) {
                previous = current;
                current = current->next;
            }
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }

        void delete_value(int value) {
            node *current = head;
            node *previous = NULL;
            while (current != NULL && current->data != value) {
                previous = current;
                current = current->next;
            }
            if (current == NULL) {
                cout << "Valor no encontrado en la lista." << endl;
                return;
            }
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
        }

        void clear() {
            node *current = head;
            while (current != NULL) {
                node *temp = current;
                current = current->next;
                delete temp;
            }
            head = NULL;
            tail = NULL;
            cout << "Lista vaciada." << endl;
        }

      bool search(int value) {
    node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            cout << "Elemento encontrado: " << value << endl;
            cout << "Dirección de memoria del nodo: " << current << endl;
            return true;
        }
        current = current->next;
    }
    cout << "Elemento no encontrado: " << value << endl;
    return false;
}

};

int main() {
     system("chcp 65001");

    // Configurar el entorno para mostrar caracteres especiales
    setlocale(LC_ALL, "es_ES.UTF-8");
    list obj;
    int choice, value, position;

    while (true) {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Insertar al final\n";
        cout << "2. Insertar al inicio\n";
        cout << "3. Insertar en una posición específica\n";
        cout << "4. Eliminar el primer elemento\n";
        cout << "5. Eliminar el último elemento\n";
        cout << "6. Eliminar un elemento en una posición específica\n";
        cout << "7. Eliminar un elemento por valor\n";
        cout << "8. Buscar un elemento\n";
        cout << "9. Vaciar la lista\n";
        cout << "10. Mostrar la lista\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Ingrese el valor a insertar al final: ";
                cin >> value;
                obj.createnode(value);
                break;

            case 2:
                cout << "Ingrese el valor a insertar al inicio: ";
                cin >> value;
                obj.insert_start(value);
                break;

            case 3:
                cout << "Ingrese la posición: ";
                cin >> position;
                cout << "Ingrese el valor a insertar en la posición " << position << ": ";
                cin >> value;
                obj.insert_position(position, value);
                break;

            case 4:
                obj.delete_first();
                cout << "Primer elemento eliminado.\n";
                break;

            case 5:
                obj.delete_last();
                cout << "Último elemento eliminado.\n";
                break;

            case 6:
                cout << "Ingrese la posición del elemento a eliminar: ";
                cin >> position;
                obj.delete_position(position);
                cout << "Elemento en posición " << position << " eliminado.\n";
                break;

            case 7:
                cout << "Ingrese el valor del elemento a eliminar: ";
                cin >> value;
                obj.delete_value(value);
                break;

            case 8:
                cout << "Ingrese el valor del elemento a buscar: ";
                cin >> value;
                obj.search(value);
                break;

            case 9:
                obj.clear();
                break;

            case 10:
                cout << "Lista actual: ";
                obj.display();
                break;

            case 0:
                cout << "Saliendo...\n";
                return 0;

            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    }

    return 0;
}
