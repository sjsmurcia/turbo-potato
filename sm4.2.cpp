#include <iostream>
using namespace std;

// Nodo de la lista enlazada circular doble
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Clase para la lista enlazada circular doble
class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    // a. Ingreso de elementos en la lista basada en su valor
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* tail = head->prev; // Último nodo
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // b. Ingreso de elementos en la lista basada en su índice
    void insertAtIndex(int index, int data) {
        Node* newNode = new Node(data);
        if (index == 0) {
            if (!head) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node* tail = head->prev;
                newNode->next = head;
                newNode->prev = tail;
                tail->next = newNode;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
            if (current == head) {
                cout << "Index out of bounds" << endl;
                delete newNode;
                return;
            }
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    // c. Eliminación de un elemento de la lista basado en su valor
    void deleteNode(int key) {
        if (!head) return;

        Node* current = head;
        do {
            if (current->data == key) {
                if (current->next == current) { // Solo un nodo
                    delete current;
                    head = nullptr;
                    return;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if (current == head) {
                        head = current->next; // Actualizar cabeza si es necesario
                    }
                    delete current;
                    return;
                }
            }
            current = current->next;
        } while (current != head);
        cout << "Node with value " << key << " not found." << endl;
    }

    // d. Vaciamiento de la lista
    void clear() {
        if (!head) return;

        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = nullptr;
    }

    // e. Búsqueda de un elemento dentro de la lista
    bool search(int key) {
        if (!head) return false;

        Node* current = head;
        do {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    // Método para imprimir la lista
    void printList() {
        if (!head) {
            cout << "Lista vacía." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "(circular)" << endl;
    }

    ~CircularDoublyLinkedList() {
        clear(); // Asegúrate de liberar memoria al destruir la lista
    }
};

// Función para agregar elementos manualmente
void addElements(CircularDoublyLinkedList &cdll) {
    int value;
    char choice;
    do {
        cout << "Ingrese un valor a agregar a la lista: ";
        cin >> value;
        cdll.append(value); // a. Ingreso de elementos en la lista basada en su valor
        cout << "¿Desea agregar otro valor? (s/n): ";
        cin >> choice;
    } while (choice == 's' || choice == 'S');
}

int main() {
     system("chcp 65001");

    // Configurar el entorno para mostrar caracteres especiales
    setlocale(LC_ALL, "es_ES.UTF-8");
    CircularDoublyLinkedList cdll;

    addElements(cdll);

    cout << "Lista después de agregar elementos manualmente: ";
    cdll.printList();

    // b. Ingreso de elementos en la lista basada en su índice
    cdll.insertAtIndex(2, 10);

    cout << "Lista después de insertar elemento en índice 2: ";
    cdll.printList();

    // c. Eliminación de un elemento de la lista basado en su valor
    cdll.deleteNode(10);

    cout << "Lista después de eliminar elemento con valor 10: ";
    cdll.printList();

    // d. Vaciamiento de la lista
    cdll.clear();

    cout << "Lista después de vaciar: ";
    cdll.printList();

    // e. Búsqueda de un elemento dentro de la lista
    cout << "¿Existe el elemento 5 en la lista? " << (cdll.search(5) ? "Sí" : "No") << endl;

    return 0;
    system("PAUSE");
}