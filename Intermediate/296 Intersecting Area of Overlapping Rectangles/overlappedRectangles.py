# Link to problem:
# https://www.reddit.com/r/dailyprogrammer/comments/5jpt8v/20161222_challenge_296_intermediate_intersecting/
# On this one I ignored the input parameters in order to work more on the logic behind the problem
# Only works in python 3.6 because I wanted to try out string interpolation
from sys import maxsize
input_rectangles = [((-3,0), (1.8,4)),
                    ((1,1), (-2.5,3.6)),
                    ((-4.1,5.75),(0.5,2)),
                    ((-1.0,4.6),(-2.9,-0.8))]

def area(rectangles):
    overlap_x1 = maxsize
    overlap_x2 = -maxsize
    overlap_y1 = maxsize
    overlap_y2 = -maxsize
    for rectangle in rectangles:
        overlap_x1 = min(overlap_x1,max(rectangle[0][0],rectangle[1][0]))
        overlap_x2 = max(overlap_x2,min(rectangle[0][0],rectangle[1][0]))
        overlap_y1 = min(overlap_y1,max(rectangle[0][1],rectangle[1][1]))
        overlap_y2 = max(overlap_y2,min(rectangle[0][1],rectangle[1][1]))
    dx = overlap_x1 - overlap_x2
    dy = overlap_y1 - overlap_y2
    if dx > 0 and dy > 0:
        print(f'{(dx * dy):.2}')
    else:
        print(0)


area(input_rectangles)