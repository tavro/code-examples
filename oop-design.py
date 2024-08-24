class OrderService:
    def __init__(self):
        self.orders = []

    def place_order(self, order):
        self.orders.append(order)
        print(f"Order placed: {order}")

    def get_order(self, order_id):
        for order in self.orders:
            if order['id'] == order_id:
                return order
        return None


class InventoryService:
    def __init__(self):
        self.inventory = {}

    def update_inventory(self, product_id, quantity):
        if product_id in self.inventory:
            self.inventory[product_id] += quantity
        else:
            self.inventory[product_id] = quantity
        print(f"Inventory updated: {product_id} = {self.inventory[product_id]}")


if __name__ == "__main__":
    order_service = OrderService()
    inventory_service = InventoryService()

    order = {'id': 1, 'product_id': 'A123', 'quantity': 2}
    order_service.place_order(order)
    inventory_service.update_inventory(order['product_id'], -order['quantity'])