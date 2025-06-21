# Binary Tree Visualizer

This repository contains a web-based tool for visualizing binary trees using an optimized positioning algorithm. The visualization dynamically renders trees from level-order input and provides interactive features to explore tree structures.

## Features

- 🎨 **Interactive Visualization**: Renders binary trees with optimal node positioning
- ⚙️ **Customizable Settings**:
  - Adjust node size (Small/Medium/Large)
  - Control animation speed (None/Slow/Medium/Fast)
  - Zoom in/out functionality
- 📊 **Tree Statistics**: Displays node count, tree height, and visualization width
- 🌐 **Responsive Design**: Works on desktop and mobile devices
- 🖥️ **Full-Screen Mode**: For detailed examination of complex trees
- 📚 **Example Trees**: Pre-configured examples for quick visualization

## Key Advantages of This Approach

### 🌳 Optimal Space Utilization
- **Balanced Layout**: Uses subtree width calculations to position nodes efficiently
- **Minimal Wasted Space**: Algorithm ensures compact representation without unnecessary gaps
- **Adaptive Scaling**: Automatically adjusts to different tree sizes and structures

### 🎯 Precision Line Connections
- **Edge-to-Edge Connections**: Lines connect to node edges rather than centers
- **Minimal Crossings**: Positioning algorithm reduces line crossings for better readability
- **Angle Optimization**: Lines follow direct paths between parent and child nodes

### ⚡ Performance Efficiency
- **O(n) Time Complexity**: Processes trees in linear time
- **Dynamic Programming Approach**: Recursive width calculation avoids redundant computations
- **Smooth Animation**: Optimized rendering even for complex trees

### 🖥️ Enhanced User Experience
- **Interactive Exploration**: Hover effects and node details on click
- **Responsive Design**: Works seamlessly across different screen sizes
- **Full-Screen Mode**: Detailed examination of large trees
- **Visual Statistics**: Real-time display of node count, height, and width

### 🔧 Algorithmic Advantages
1. **Subtree Width Calculation**:
   ```cpp
   int widthSubTree(TreeNode* node) {
       if (!node) return 0;
       node->leftwidth = widthSubTree(node->left);
       node->rightwidth = widthSubTree(node->right);
       return 1 + node->leftwidth + node->rightwidth;
   }```

## How to Use

1. Enter your tree in **level-order format** in the input box:
   - Use commas to separate values
   - Represent empty nodes with `null`
   - Example: `1,2,3,null,4,5,6`

2. Adjust visualization settings:
   - **Node Size**: Control node display size
   - **Animation Speed**: Set rendering animation speed
   - **Tree Scaling**: Zoom in/out or reset view

3. Click "Visualize Tree" to render your binary tree

4. Interact with the visualization:
   - Hover over nodes to highlight them
   - Click nodes to view details
   - Use full-screen mode for complex trees
   - Scroll to navigate large visualizations

## Example Inputs

Try these sample trees:

| Tree Type | Input |
|-----------|-------|
| Complex Tree | `50, 25, 75, 2, null, 55, null, null, 5, null, 59, 4, 6, 58, null, null, null, null, 7, 57, null` |
| Complete Binary Tree | `1,2,3,4,5,6,7,8,9,10,11,12,13,14,15` |
| Balanced Tree | `1,2,3,null,4,5,6,null,null,7,8,9,10` |
| Left-heavy Tree | `1,2,null,3,4,null,null,5,6,7,8` |
