import matplotlib.pyplot as plt

def is_point_inside_triangle(p, p1, p2, p3):
    def sign(p1, p2, p3):
        return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1])

    d1 = sign(p, p1, p2)
    d2 = sign(p, p2, p3)
    d3 = sign(p, p3, p1)

    has_neg = (d1 < 0) or (d2 < 0) or (d3 < 0)
    has_pos = (d1 > 0) or (d2 > 0) or (d3 > 0)

    return not (has_neg and has_pos)

def plot_triangle_with_point(p1, p2, p3, marked_point):
    x = [p1[0], p2[0], p3[0], p1[0]]
    y = [p1[1], p2[1], p3[1], p1[1]]

    plt.plot(x, y, marker='o', linestyle='-')

    plt.scatter(*marked_point, color='red', label='Marked Point')

    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Triangle with Marked Point')
    plt.legend()
    plt.grid(True)
    plt.show()

p1 = tuple(map(float, input("Enter coordinates for point 1 (comma-separated): ").split(',')))
p2 = tuple(map(float, input("Enter coordinates for point 2 (comma-separated): ").split(',')))
p3 = tuple(map(float, input("Enter coordinates for point 3 (comma-separated): ").split(',')))
marked_point = tuple(map(float, input("Enter coordinates for the marked point (comma-separated): ").split(',')))

# Plot the triangle with the marked point
plot_triangle_with_point(p1, p2, p3, marked_point)

# Check if the marked point is inside the triangle
result = is_point_inside_triangle(marked_point, p1, p2, p3)
if (result):
	print(f"The marked point is inside the triangle")
else:
	print(f"The marked point is outside the triangle")
