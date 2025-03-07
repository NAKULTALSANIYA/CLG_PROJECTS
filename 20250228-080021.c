CREATE TABLE Users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    date_of_birth DATE,
    phone_number VARCHAR(15),
    subscription_status VARCHAR(50) DEFAULT 'Inactive'
);

CREATE TABLE Content (
    content_id INT AUTO_INCREMENT PRIMARY KEY,
    content_type VARCHAR(50) NOT NULL,  -- Movie or TV Show
    title VARCHAR(255) NOT NULL,
    description TEXT,
    language VARCHAR(50),
    release_year YEAR,
    duration INT,  -- In minutes for movies
    seasons INT,  -- For TV Shows
    episodes INT,  -- For TV Shows
    rating DECIMAL(3,1)
);

CREATE TABLE Subscription (
    subscription_id INT AUTO_INCREMENT PRIMARY KEY,
    plan_type VARCHAR(50) NOT NULL,  -- Basic, Premium, etc.
    price DECIMAL(10,2) NOT NULL,
    duration_months INT,  -- Subscription duration in months
);

CREATE TABLE User_Subscription (
    user_subscription_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    subscription_id INT NOT NULL,
    start_date DATE NOT NULL,
    end_date DATE,
    status VARCHAR(50) DEFAULT 'Active',
    FOREIGN KEY (user_id) REFERENCES Users(user_id),
    FOREIGN KEY (subscription_id) REFERENCES Subscription(subscription_id)
);

CREATE TABLE Payment (
    payment_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    amount_paid DECIMAL(10,2) NOT NULL,
    payment_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    payment_status VARCHAR(50) DEFAULT 'Completed',  -- Completed, Failed, Pending
    payment_method VARCHAR(50),  -- Credit Card, PayPal, etc.
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

CREATE TABLE Watch_History (
    history_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    content_id INT NOT NULL,
    watched_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    progress DECIMAL(5,2),  -- Watch progress percentage
    FOREIGN KEY (user_id) REFERENCES Users(user_id),
    FOREIGN KEY (content_id) REFERENCES Content(content_id)
);

CREATE TABLE Reviews (
    review_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    content_id INT NOT NULL,
    rating DECIMAL(3,1) NOT NULL,  -- Rating out of 5
    review_text TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES Users(user_id),
    FOREIGN KEY (content_id) REFERENCES Content(content_id)
);

CREATE TABLE Categories (
    category_id INT AUTO_INCREMENT PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL
);

CREATE TABLE Content_Category (
    content_id INT NOT NULL,
    category_id INT NOT NULL,
    PRIMARY KEY (content_id, category_id),
    FOREIGN KEY (content_id) REFERENCES Content(content_id),
    FOREIGN KEY (category_id) REFERENCES Categories(category_id)
);

INSERT INTO Content (content_type, title, description, language, release_year, duration, seasons, episodes, rating) 
VALUES
('Movie', 'Inception', 'A mind-bending thriller about dreams within dreams.', 'English', 2010, 148, NULL, NULL, 4.8),
('TV Show', 'Stranger Things', 'A group of kids uncover dark secrets about their town.', 'English', 2016, NULL, 4, 34, 4.7),
('Movie', 'The Dark Knight', 'Batman battles the Joker to save Gotham City.', 'English', 2008, 152, NULL, NULL, 4.9),
('TV Show', 'Breaking Bad', 'A high school teacher turned meth maker descends into crime.', 'English', 2008, NULL, 5, 62, 4.9),
('Movie', 'Avengers: Endgame', 'The Avengers must undo the damage caused by Thanos.', 'English', 2019, 181, NULL, NULL, 4.7),
('Movie', 'The Matrix', 'A hacker discovers the world he lives in is a simulation.', 'English', 1999, 136, NULL, NULL, 4.6),
('TV Show', 'Game of Thrones', 'Noble families battle for control of the Iron Throne.', 'English', 2011, NULL, 8, 73, 4.8),
('Movie', 'Interstellar', 'A team of astronauts travel through a wormhole to save humanity.', 'English', 2014, 169, NULL, NULL, 4.7);

INSERT INTO Subscription (plan_type, price, duration_months) 
VALUES
('Basic', 9.99, 1),
('Premium', 19.99, 1),
('Standard', 14.99, 1),
('Family', 29.99, 1),
('Basic', 9.99, 12),
('Premium', 19.99, 12),
('Standard', 14.99, 12),
('Family', 29.99, 12);

INSERT INTO User_Subscription (user_id, subscription_id, start_date, end_date, status) 
VALUES
(1, 2, '2025-01-01', '2025-12-31', 'Active'),
(2, 3, '2025-02-01', '2025-08-01', 'Active'),
(3, 4, '2025-03-01', '2026-03-01', 'Active'),
(4, 1, '2025-01-15', '2025-02-15', 'Inactive'),
(5, 2, '2025-02-10', '2025-08-10', 'Active'),
(6, 3, '2025-03-05', '2026-03-05', 'Active'),
(7, 1, '2025-01-01', '2025-12-31', 'Inactive'),
(8, 4, '2025-01-20', '2026-01-20', 'Active');

INSERT INTO Payment (user_id, amount_paid, payment_date, payment_status, payment_method) 
VALUES
(1, 19.99, '2025-01-01 10:00:00', 'Completed', 'Credit Card'),
(2, 14.99, '2025-02-01 12:00:00', 'Completed', 'PayPal'),
(3, 29.99, '2025-03-01 09:30:00', 'Completed', 'Credit Card'),
(4, 9.99, '2025-01-15 14:00:00', 'Failed', 'PayPal'),
(5, 19.99, '2025-02-10 16:00:00', 'Completed', 'Credit Card'),
(6, 14.99, '2025-03-05 11:30:00', 'Completed', 'Credit Card'),
(7, 9.99, '2025-01-01 09:00:00', 'Pending', 'Credit Card'),
(8, 29.99, '2025-01-20 15:45:00', 'Completed', 'PayPal');

INSERT INTO Watch_History (user_id, content_id, watched_at, progress) 
VALUES
(1, 1, '2025-01-05 08:00:00', 100),
(2, 2, '2025-02-01 13:00:00', 85),
(3, 3, '2025-03-03 18:00:00', 100),
(4, 4, '2025-01-17 10:30:00', 50),
(5, 5, '2025-02-15 09:30:00', 100),
(6, 6, '2025-03-06 20:00:00', 75),
(7, 7, '2025-01-03 14:00:00', 100),
(8, 8, '2025-01-22 17:30:00', 60);

INSERT INTO Reviews (user_id, content_id, rating, review_text, created_at) 
VALUES
(1, 1, 5, 'Incredible movie! A mind-bending experience.', '2025-01-06 09:00:00'),
(2, 2, 4, 'Great show, but I wish the pacing was a bit faster.', '2025-02-02 10:00:00'),
(3, 3, 5, 'Masterpiece! One of the best superhero movies ever made.', '2025-03-04 11:00:00'),
(4, 4, 3, 'Good, but a bit slow at times.', '2025-01-18 12:00:00'),
(5, 5, 5, 'Epic conclusion to the Avengers saga. Loved it.', '2025-02-16 14:00:00'),
(6, 6, 4, 'Mind-blowing concept, but could have been better executed.', '2025-03-07 12:30:00'),
(7, 7, 5, 'Best show ever! Can\'t wait for the next season.', '2025-01-04 13:00:00'),
(8, 8, 4, 'Great visuals, but the story was a bit confusing.', '2025-01-23 16:00:00');

INSERT INTO Categories (category_name) 
VALUES
('Action'),
('Drama'),
('Comedy'),
('Sci-Fi'),
('Thriller'),
('Fantasy'),
('Romance'),
('Adventure');

INSERT INTO Content_Category (content_id, category_id) 
VALUES
(1, 1),  -- Inception -> Action
(2, 2),  -- Stranger Things -> Drama
(3, 1),  -- The Dark Knight -> Action
(4, 2),  -- Breaking Bad -> Drama
(5, 1),  -- Avengers: Endgame -> Action
(6, 4),  -- The Matrix -> Sci-Fi
(7, 2),  -- Game of Thrones -> Drama
(8, 4);  -- Interstellar -> Sci-Fi

INSERT INTO Users (first_name, last_name, email, password_hash, date_of_birth, phone_number, subscription_status) 
VALUES
('Aarav', 'Sharma', 'aarav.sharma@example.com', 'hashed_password_123', '1990-05-12', '9876543210', 'Active'),
('Isha', 'Patel', 'isha.patel@example.com', 'hashed_password_456', '1992-08-25', '9998765432', 'Inactive'),
('Ravi', 'Verma', 'ravi.verma@example.com', 'hashed_password_789', '1985-02-19', '9101112131', 'Active'),
('Priya', 'Reddy', 'priya.reddy@example.com', 'hashed_password_101', '1993-11-01', '9123456789', 'Suspended'),
('Vikram', 'Singh', 'vikram.singh@example.com', 'hashed_password_202', '1987-04-22', '9008776655', 'Active'),
('Ananya', 'Gupta', 'ananya.gupta@example.com', 'hashed_password_303', '1995-03-10', '9456781234', 'Active'),
('Arjun', 'Kumar', 'arjun.kumar@example.com', 'hashed_password_404', '1988-09-06', '9976554433', 'Inactive'),
('Neha', 'Joshi', 'neha.joshi@example.com', 'hashed_password_505', '1990-12-14', '9988776655', 'Active');

INSERT INTO Users (first_name, last_name, email, password_hash, date_of_birth, phone_number) 
VALUES ('John', 'Doe', 'john.doe@example.com', 'hashed_password', '1990-05-15', '1234567890');

INSERT INTO Content (content_type, title, description, language, release_year, duration, rating) 
VALUES ('Movie', 'Inception', 'A mind-bending thriller', 'English', 2010, 148, 8.8);

INSERT INTO Subscription (plan_type, price, duration_months) 
VALUES ('Premium', 15.99, 1);

UPDATE Users 
SET subscription_status = 'Active' 
WHERE user_id = 1;

UPDATE Content 
SET rating = 9.0 
WHERE content_id = 1;

UPDATE Payment 
SET payment_status = 'Failed' 
WHERE payment_id = 1;

DELETE FROM Users 
WHERE user_id = 2;

DELETE FROM Content 
WHERE content_id = 3;

SELECT * FROM Content 
WHERE content_type = 'Movie' AND release_year > 2010;

SELECT * FROM User_Subscription 
WHERE status = 'Active';

SELECT u.user_id, u.first_name, u.last_name, s.plan_type, s.price, us.start_date, us.end_date
FROM Users u
JOIN User_Subscription us ON u.user_id = us.user_id
JOIN Subscription s ON us.subscription_id = s.subscription_id;

SELECT u.first_name, u.last_name, c.title, wh.watched_at, wh.progress
FROM Watch_History wh
JOIN Users u ON wh.user_id = u.user_id
JOIN Content c ON wh.content_id = c.content_id;

SELECT u.first_name, u.last_name, c.title, r.rating, r.review_text, r.created_at
FROM Reviews r
JOIN Users u ON r.user_id = u.user_id
JOIN Content c ON r.content_id = c.content_id;

SELECT COUNT(*) AS total_users FROM Users;

SELECT title, AVG(rating) AS average_rating
FROM Reviews r
JOIN Content c ON r.content_id = c.content_id
WHERE c.content_id = 1
GROUP BY c.title;

SELECT SUM(amount_paid) AS total_revenue FROM Payment WHERE payment_status = 'Completed';

SELECT c.title, COUNT(*) AS watch_count
FROM Watch_History wh
JOIN Content c ON wh.content_id = c.content_id
GROUP BY c.title
ORDER BY watch_count DESC
LIMIT 1;

SELECT u.user_id, u.first_name, u.last_name, us.status
FROM Users u
JOIN User_Subscription us ON u.user_id = us.user_id
WHERE us.status = 'Active';

DELIMITER //
CREATE PROCEDURE AddUser(
    IN p_first_name VARCHAR(255),
    IN p_last_name VARCHAR(255),
    IN p_email VARCHAR(255),
    IN p_password_hash VARCHAR(255),
    IN p_date_of_birth DATE,
    IN p_phone_number VARCHAR(15),
    OUT p_user_id INT
)
BEGIN
    INSERT INTO Users (first_name, last_name, email, password_hash, date_of_birth, phone_number)
    VALUES (p_first_name, p_last_name, p_email, p_password_hash, p_date_of_birth, p_phone_number);
    
    SET p_user_id = LAST_INSERT_ID();
END //
DELIMITER ;

CALL AddUser('Alice', 'Smith', 'alice.smith@example.com', 'hashed_pass', '1992-08-10', '9876543210', @new_user_id);
SELECT @new_user_id;  -- Check the newly created user ID

DELIMITER //
CREATE PROCEDURE GetUserSubscription(
    IN p_user_id INT
)
BEGIN
    SELECT u.user_id, u.first_name, u.last_name, s.plan_type, s.price, us.start_date, us.end_date, us.status
    FROM Users u
    JOIN User_Subscription us ON u.user_id = us.user_id
    JOIN Subscription s ON us.subscription_id = s.subscription_id
    WHERE u.user_id = p_user_id;
END //
DELIMITER ;

CALL GetUserSubscription(1);

DELIMITER //
CREATE PROCEDURE UpdateSubscriptionStatus(
    IN p_user_id INT,
    IN p_status VARCHAR(50)
)
BEGIN
    UPDATE User_Subscription
    SET status = p_status
    WHERE user_id = p_user_id;
END //
DELIMITER ;


CALL UpdateSubscriptionStatus(1, 'Expired');
SELECT * FROM User_Subscription WHERE user_id = 1;  -- Verify the update

DELIMITER //
CREATE PROCEDURE AddPayment(
    IN p_user_id INT,
    IN p_amount_paid DECIMAL(10,2),
    IN p_payment_method VARCHAR(50),
    OUT p_payment_id INT
)
BEGIN
    INSERT INTO Payment (user_id, amount_paid, payment_method)
    VALUES (p_user_id, p_amount_paid, p_payment_method);
    
    SET p_payment_id = LAST_INSERT_ID();
END //
DELIMITER ;

CALL AddPayment(1, 15.99, 'Credit Card', @new_payment_id);
SELECT @new_payment_id;  -- Verify the new payment ID

DELIMITER //
CREATE PROCEDURE GetMostWatchedContent()
BEGIN
    SELECT c.title, COUNT(*) AS watch_count
    FROM Watch_History wh
    JOIN Content c ON wh.content_id = c.content_id
    GROUP BY c.title
    ORDER BY watch_count DESC
    LIMIT 1;
END //
DELIMITER ;

CALL GetMostWatchedContent();

DELIMITER //
CREATE PROCEDURE CalculateTotalRevenue(OUT p_total_revenue DECIMAL(10,2))
BEGIN
    SELECT SUM(amount_paid) INTO p_total_revenue
    FROM Payment
    WHERE payment_status = 'Completed';
END //
DELIMITER ;

CALL CalculateTotalRevenue(@total_revenue);
SELECT @total_revenue;  -- Check total revenue

DELIMITER //
CREATE FUNCTION GetUserAge(user_id INT) 
RETURNS INT DETERMINISTIC
BEGIN
    DECLARE user_age INT;
    SELECT TIMESTAMPDIFF(YEAR, date_of_birth, CURDATE()) INTO user_age
    FROM Users 
    WHERE user_id = user_id;
    RETURN user_age;
END //
DELIMITER ;

SELECT GetUserAge(1) AS UserAge;

DELIMITER //
CREATE FUNCTION GetAverageRating(content_id INT) 
RETURNS DECIMAL(3,1) DETERMINISTIC
BEGIN
    DECLARE avg_rating DECIMAL(3,1);
    SELECT AVG(rating) INTO avg_rating 
    FROM Reviews 
    WHERE content_id = content_id;
    RETURN COALESCE(avg_rating, 0);
END //
DELIMITER ;

SELECT GetAverageRating(1) AS AvgRating;

DELIMITER //
CREATE FUNCTION GetActiveSubscriptions(user_id INT) 
RETURNS TABLE
RETURN 
    SELECT u.user_id, u.first_name, u.last_name, s.plan_type, us.start_date, us.end_date
    FROM Users u
    JOIN User_Subscription us ON u.user_id = us.user_id
    JOIN Subscription s ON us.subscription_id = s.subscription_id
    WHERE u.user_id = user_id AND us.status = 'Active';
//
DELIMITER ;

SELECT * FROM GetActiveSubscriptions(1);

DELIMITER //
CREATE FUNCTION GetUserWatchHistory(user_id INT) 
RETURNS TABLE
RETURN 
    SELECT wh.history_id, c.title, wh.watched_at, wh.progress
    FROM Watch_History wh
    JOIN Content c ON wh.content_id = c.content_id
    WHERE wh.user_id = user_id;
//
DELIMITER ;

SELECT * FROM GetUserWatchHistory(1);

DELIMITER //
CREATE TRIGGER LogSubscriptionChanges
AFTER UPDATE ON User_Subscription
FOR EACH ROW
BEGIN
    INSERT INTO Subscription_Log (user_id, old_status, new_status, changed_at)
    VALUES (OLD.user_id, OLD.status, NEW.status, NOW());
END;
//
DELIMITER ;

UPDATE User_Subscription 
SET status = 'Expired' 
WHERE user_id = 1;

SELECT * FROM Subscription_Log; -- Check the log for recorded changes

DELIMITER //
CREATE TRIGGER PreventDowngrade
BEFORE UPDATE ON User_Subscription
FOR EACH ROW
BEGIN
    DECLARE old_price DECIMAL(10,2);
    SELECT price INTO old_price FROM Subscription WHERE subscription_id = OLD.subscription_id;

    IF old_price > (SELECT price FROM Subscription WHERE subscription_id = NEW.subscription_id) THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Downgrading subscription is not allowed.';
    END IF;
END;
//
DELIMITER ;

UPDATE User_Subscription 
SET subscription_id = (SELECT subscription_id FROM Subscription WHERE plan_type = 'Basic') 
WHERE user_id = 1;

DELIMITER //
CREATE TRIGGER LogContentDeletion
BEFORE DELETE ON Content
FOR EACH ROW
BEGIN
    INSERT INTO Content_Log (content_id, title, deleted_at)
    VALUES (OLD.content_id, OLD.title, NOW());
END;
//
DELIMITER ;

DELETE FROM Content WHERE content_id = 1;
SELECT * FROM Content_Log; -- Verify deletion log

DELIMITER //
CREATE PROCEDURE UpdateWatchStatus()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE user_id_var INT;
    DECLARE content_id_var INT;
    DECLARE cur CURSOR FOR 
        SELECT user_id, content_id FROM Watch_History WHERE progress = 100;
    
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    
    OPEN cur;
    
    read_loop: LOOP
        FETCH cur INTO user_id_var, content_id_var;
        IF done THEN 
            LEAVE read_loop;
        END IF;

        -- Mark content as completed
        UPDATE Watch_History SET status = 'Completed' 
        WHERE user_id = user_id_var AND content_id = content_id_var;
    END LOOP;
    
    CLOSE cur;
END;
//
DELIMITER ;

CALL UpdateWatchStatus();
SELECT * FROM Watch_History WHERE status = 'Completed'; -- Verify updates

DELIMITER //
CREATE PROCEDURE SendPaymentReminders()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE user_email VARCHAR(255);
    DECLARE cur CURSOR FOR 
        SELECT email FROM Users WHERE user_id IN 
            (SELECT user_id FROM Payment WHERE payment_status = 'Pending');
    
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    
    OPEN cur;
    
    read_loop: LOOP
        FETCH cur INTO user_email;
        IF done THEN 
            LEAVE read_loop;
        END IF;

        -- Simulate sending an email (In a real app, integrate with a mail API)
        INSERT INTO Payment_Reminders (email, reminder_sent_at) VALUES (user_email, NOW());
    END LOOP;
    
    CLOSE cur;
END;
//
DELIMITER ;

CALL SendPaymentReminders();
SELECT * FROM Payment_Reminders; -- Check reminder log
