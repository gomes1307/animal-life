import java.awt.*;
import java.awt.event.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Random;
import javax.swing.*;

public class PacMan extends JPanel implements ActionListener, KeyListener {
    class Block {
        int x, y, width, height;
        int startX, startY;
        char direction = 'U';
        char nextDirection = 'U';
        int velocityX = 0, velocityY = 0;
        Image image;

        Block(Image image, int x, int y, int width, int height) {
            this.image = image;
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.startX = x;
            this.startY = y;
        }

        void updateDirection(char direction) {
            this.direction = direction;
            updateVelocity();
        }

        void updateVelocity() {
            int step = tileSize / 4;
            switch (this.direction) {
                case 'U': velocityX = 0; velocityY = -step; break;
                case 'D': velocityX = 0; velocityY = step; break;
                case 'L': velocityX = -step; velocityY = 0; break;
                case 'R': velocityX = step; velocityY = 0; break;
            }
        }

        void reset() {
            this.x = this.startX;
            this.y = this.startY;
            this.velocityX = 0;
            this.velocityY = 0;
        }
    }

    private int rowCount = 21, columnCount = 19;
    private int tileSize = 32;
    private int boardWidth = columnCount * tileSize;
    private int boardHeight = rowCount * tileSize;

    private Image wallImage, blueGhostImage, orangeGhostImage, pinkGhostImage, redGhostImage;
    private Image pacmanUpImage, pacmanDownImage, pacmanLeftImage, pacmanRightImage;

    private String[] tileMap = {
        "XXXXXXXXXXXXXXXXXXX",
        "X        X        X",
        "X XX XXX X XXX XX X",
        "X                 X",
        "X XX X XXXXX X XX X",
        "X    X       X    X",
        "XXXX XXXX XXXX XXXX",
        "OOOX X       X XOOO",
        "XXXX X XXrXX X XXXX",
        "O       bpo       O",
        "XXXX X XXXXX X XXXX",
        "OOOX X       X XOOO",
        "XXXX X XXXXX X XXXX",
        "X        X        X",
        "X XX XXX X XXX XX X",
        "X  X     P     X  X",
        "XX X X XXXXX X X XX",
        "X    X   X   X    X",
        "X XXXXXX X XXXXXX X",
        "X                 X",
        "XXXXXXXXXXXXXXXXXXX"
    };

    HashSet<Block> walls, foods;
    java.util.List<Block> ghosts = new java.util.ArrayList<>();
    Block pacman;

    Timer gameLoop;
    Random random = new Random();
    int score = 0, lives = 3;

    // --- Power-up fields (spawn once at random time) ---
    Block powerUp = null;
    Timer powerUpSpawnTimer = null;
    boolean powerUpSpawned = false;
    int powerUpSize = 8;

    enum GameState { MENU, PLAYING, GAME_OVER }
    GameState currentState = GameState.MENU;

    JButton startButton, restartButton;

    PacMan() {
        setPreferredSize(new Dimension(boardWidth, boardHeight));
        setBackground(Color.BLACK);
        setLayout(null);
        addKeyListener(this);
        setFocusable(true);

        wallImage = new ImageIcon(getClass().getResource("./wall.png")).getImage();
        blueGhostImage = new ImageIcon(getClass().getResource("./blueGhost.png")).getImage();
        orangeGhostImage = new ImageIcon(getClass().getResource("./orangeGhost.png")).getImage();
        pinkGhostImage = new ImageIcon(getClass().getResource("./pinkGhost.png")).getImage();
        redGhostImage = new ImageIcon(getClass().getResource("./redGhost.png")).getImage();

        pacmanUpImage = new ImageIcon(getClass().getResource("./pacmanUp.png")).getImage();
        pacmanDownImage = new ImageIcon(getClass().getResource("./pacmanDown.png")).getImage();
        pacmanLeftImage = new ImageIcon(getClass().getResource("./pacmanLeft.png")).getImage();
        pacmanRightImage = new ImageIcon(getClass().getResource("./pacmanRight.png")).getImage();

        startButton = new JButton("Start Game");
        startButton.setBounds(boardWidth / 2 - 80, boardHeight / 2, 160, 40);
        startButton.addActionListener(e -> {
            currentState = GameState.PLAYING;
            remove(startButton);
            requestFocusInWindow();
            startGame();
        });
        add(startButton);

        restartButton = new JButton("Restart");
        restartButton.setBounds(boardWidth / 2 - 80, boardHeight / 2 + 50, 160, 40);
        restartButton.addActionListener(e -> {
            currentState = GameState.PLAYING;
            remove(restartButton);
            requestFocusInWindow();
            startGame();
        });

        gameLoop = new Timer(50, this); // Pac-Man movement speed
    }

    public void startGame() {
        loadMap();
        score = 0;
        lives = 3;

        // Give each ghost its own timer
        for (Block ghost : ghosts) {
            Timer ghostTimer = new Timer(100,e -> moveGhost(ghost)); // move individually
            ghostTimer.start();
        }

        // Schedule a one-time power-up spawn at a random delay (10-30s)
        if (powerUpSpawnTimer != null) {
            powerUpSpawnTimer.stop();
        }
        powerUpSpawned = false;
        int delay = 10000 + random.nextInt(20000); // 10-30 seconds
        powerUpSpawnTimer = new Timer(delay, e -> {
            spawnPowerUp();
            if (powerUpSpawnTimer != null) powerUpSpawnTimer.stop();
        });
        powerUpSpawnTimer.setRepeats(false);
        powerUpSpawnTimer.start();

        gameLoop.start();
    }

    public void loadMap() {
        walls = new HashSet<>();
        foods = new HashSet<>();
        ghosts.clear();

        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < columnCount; c++) {
                char ch = tileMap[r].charAt(c);
                int x = c * tileSize;
                int y = r * tileSize;

                switch (ch) {
                    case 'X':
                        walls.add(new Block(wallImage, x, y, tileSize, tileSize));
                        break;
                    case 'b':
                        ghosts.add(new Block(blueGhostImage, x, y, tileSize, tileSize));
                        break;
                    case 'o':
                        ghosts.add(new Block(orangeGhostImage, x, y, tileSize, tileSize));
                        break;
                    case 'p':
                        ghosts.add(new Block(pinkGhostImage, x, y, tileSize, tileSize));
                        break;
                    case 'r':
                        ghosts.add(new Block(redGhostImage, x, y, tileSize, tileSize));
                        break;
                    case 'P':
                        pacman = new Block(pacmanRightImage, x, y, tileSize, tileSize);
                        break;
                    case ' ':
                        foods.add(new Block(null, x + 14, y + 14, 4, 4));
                        break;
                }
            }
        }

        for (Block ghost : ghosts) {
            ghost.updateDirection(randomDir());
        }

        // ensure any previous power-up is cleared when loading map
        powerUp = null;
        powerUpSpawned = false;
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        if (currentState == GameState.MENU) {
            g.setColor(Color.YELLOW);
            g.setFont(new Font("Arial", Font.BOLD, 48));
            g.drawString("PAC-MAN", boardWidth / 2 - 100, boardHeight / 2 - 50);
            return;
        }

        drawGame(g);

        if (currentState == GameState.GAME_OVER) {
            g.setColor(Color.RED);
            g.setFont(new Font("Arial", Font.BOLD, 48));
            g.drawString("GAME OVER", boardWidth / 2 - 150, boardHeight / 2 - 50);
        }
    }

    public void drawGame(Graphics g) {
        g.drawImage(pacman.image, pacman.x, pacman.y, pacman.width, pacman.height, null);

        for (Block ghost : ghosts) {
            g.drawImage(ghost.image, ghost.x, ghost.y, ghost.width, ghost.height, null);
        }

        for (Block wall : walls) {
            g.drawImage(wall.image, wall.x, wall.y, wall.width, wall.height, null);
        }

        g.setColor(Color.WHITE);
        for (Block food : foods) {
            g.fillRect(food.x, food.y, food.width, food.height);
        }

        // draw single power-up (distinct color/shape)
        if (powerUp != null) {
            g.setColor(Color.MAGENTA);
            g.fillOval(powerUp.x, powerUp.y, powerUp.width, powerUp.height);
        }

        g.setFont(new Font("Arial", Font.BOLD, 18));
        g.drawString("Lives: " + lives + " Score: " + score, tileSize, tileSize);
    }

    public void move() {
        if (currentState != GameState.PLAYING) return;

        if (canMove(pacman, pacman.nextDirection)) {
            pacman.updateDirection(pacman.nextDirection);
        }

        pacman.x += pacman.velocityX;
        pacman.y += pacman.velocityY;

        for (Block wall : walls) {
            if (collision(pacman, wall)) {
                pacman.x -= pacman.velocityX;
                pacman.y -= pacman.velocityY;
                break;
            }
        }

        if (pacman.x < 0) pacman.x = boardWidth - tileSize;
        if (pacman.x >= boardWidth) pacman.x = 0;

        Iterator<Block> it = foods.iterator();
        while (it.hasNext()) {
            Block food = it.next();
            if (collision(pacman, food)) {
                it.remove();
                score += 10;
                break;
            }
        }

        // check power-up collision: if eaten, give extra life and remove it
        if (powerUp != null && collision(pacman, powerUp)) {
            lives += 1;
            powerUp = null;
            powerUpSpawned = true;
        }

        if (foods.isEmpty()) {
            currentState = GameState.GAME_OVER;
            gameLoop.stop();
            showRestartButton();
        }

        // Check ghost collision
        for (Block ghost : ghosts) {
            if (collision(ghost, pacman)) {
                lives--;
                if (lives <= 0) {
                    currentState = GameState.GAME_OVER;
                    gameLoop.stop();
                    showRestartButton();
                    return;
                }
                resetPositions();
                break;
            }
        }
    }

    private void moveGhost(Block ghost) {
        if (currentState != GameState.PLAYING) return;

        // Simple AI: sometimes chase Pac-Man
        if (random.nextInt(5) == 0) {
            char chaseDir = getChaseDirection(ghost);
            if (canMove(ghost, chaseDir)) {
                ghost.updateDirection(chaseDir);
            }
        }

        ghost.x += ghost.velocityX;
        ghost.y += ghost.velocityY;

        if (ghost.x < 0) ghost.x = boardWidth - tileSize;
        if (ghost.x >= boardWidth) ghost.x = 0;

        for (Block wall : walls) {
            if (collision(ghost, wall)) {
                ghost.x -= ghost.velocityX;
                ghost.y -= ghost.velocityY;
                ghost.updateDirection(randomDir());
                break;
            }
        }
        repaint();
    }

    private char randomDir() {
        char[] dirs = {'U', 'D', 'L', 'R'};
        return dirs[random.nextInt(4)];
    }

    private char getChaseDirection(Block ghost) {
        int dx = pacman.x - ghost.x;
        int dy = pacman.y - ghost.y;
        if (Math.abs(dx) > Math.abs(dy)) {
            return dx > 0 ? 'R' : 'L';
        } else {
            return dy > 0 ? 'D' : 'U';
        }
    }

    public boolean collision(Block a, Block b) {
        return a.x < b.x + b.width &&
               a.x + a.width > b.x &&
               a.y < b.y + b.height &&
               a.y + a.height > b.y;
    }

    public boolean canMove(Block b, char direction) {
        int testX = b.x;
        int testY = b.y;
        int step = tileSize / 4;

        switch (direction) {
            case 'U': testY -= step; break;
            case 'D': testY += step; break;
            case 'L': testX -= step; break;
            case 'R': testX += step; break;
        }

        Block test = new Block(null, testX, testY, b.width, b.height);
        for (Block wall : walls) {
            if (collision(test, wall)) return false;
        }
        return true;
    }

    private void spawnPowerUp() {
        if (powerUpSpawned) return;
        if (foods == null || foods.isEmpty()) return;

        // pick a random food to replace with power-up (so it appears on a valid free tile)
        int idx = random.nextInt(foods.size());
        Block chosen = null;
        int i = 0;
        for (Block f : foods) {
            if (i++ == idx) {
                chosen = f;
                break;
            }
        }
        if (chosen != null) {
            foods.remove(chosen);
            // center a slightly larger oval on that food position
            powerUp = new Block(null, chosen.x - (powerUpSize - chosen.width)/2, chosen.y - (powerUpSize - chosen.height)/2, powerUpSize, powerUpSize);
            powerUpSpawned = true;
            repaint();
        }
    }

    public void resetPositions() {
        pacman.reset();
        for (Block ghost : ghosts) {
            ghost.reset();
            ghost.updateDirection(randomDir());
        }
        // do not automatically respawn powerup on death; it remains until used (or startGame resets)
    }

    private void showRestartButton() {
        // stop any pending power-up spawn when game over and show restart
        if (powerUpSpawnTimer != null) {
            powerUpSpawnTimer.stop();
        }
        add(restartButton);
        repaint();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        move();
        repaint();
    }

    @Override public void keyTyped(KeyEvent e) {}
    @Override public void keyPressed(KeyEvent e) {}

    @Override
    public void keyReleased(KeyEvent e) {
        if (currentState != GameState.PLAYING) return;

        int key = e.getKeyCode();
        switch (key) {
            case KeyEvent.VK_UP:
                pacman.nextDirection = 'U';
                pacman.image = pacmanUpImage;
                break;
            case KeyEvent.VK_DOWN:
                pacman.nextDirection = 'D';
                pacman.image = pacmanDownImage;
                break;
            case KeyEvent.VK_LEFT:
                pacman.nextDirection = 'L';
                pacman.image = pacmanLeftImage;
                break;
            case KeyEvent.VK_RIGHT:
                pacman.nextDirection = 'R';
                pacman.image = pacmanRightImage;
                break;
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Pac-Man");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new PacMan());
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
