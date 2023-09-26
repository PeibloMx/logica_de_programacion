import matplotlib.pyplot as plt

"""se le pide al usuario y se grafica"""
def bresenham(x1, y1, x2, y2):
    deltax = abs(x2 - x1)
    deltay = abs(y2 - y1)
    
    if x1 < x2:
        sx = 1
    else: 
        sx = -1
    

    if y1 < y2:
        sy = 1
    else:
        sy = -1 
    
    err = deltax - deltay
    
    puntos = []
    
    i = 1
    while True:
        puntos.append((x1, y1))
        print(f"({x1}, {y1})")
        
        if x1 == x2 and y1 == y2:
            break
        
        # Cálculo del error acumulado
        e2 = 2 * err
        
        if e2 > -deltay:
            err -= deltay
            x1 += sx
            
        if e2 < deltax:
            err += deltax
            y1 += sy
            
    return puntos

x0 = int(input("Introduce x1: "))
y0 = int(input("Introduce y1: "))
x1 = int(input("Introduce x2: "))
y1 = int(input("Introduce y2: "))


puntos = bresenham(x0, y0, x1, y1)

x_values = [x[0] for x in puntos]
y_values = [x[1] for x in puntos]

plt.plot(x_values, y_values, 'gs')
plt.plot(x_values, y_values)
plt.show()
