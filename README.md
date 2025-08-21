# Four Screens App

A Flutter app with four screens (Home, Explore, Favorites, Profile), an eye-catching glassmorphism UI, and a modern Material 3 theme using Google Fonts.

## Requirements
- Flutter SDK (3.19+ recommended)

## Setup and run
```bash
# If this directory is not yet a full Flutter project, scaffold platforms and configs
flutter create .

flutter pub get
flutter run -d chrome   # or your connected device
```

## Project structure
```
lib/
  main.dart
  theme/app_theme.dart
  widgets/glass_card.dart
  screens/
    home_screen.dart
    explore_screen.dart
    favorites_screen.dart
    profile_screen.dart
```

## Notes
- Uses `google_fonts` and Material 3 theming.
- Designed with soft gradients and glass-like cards.