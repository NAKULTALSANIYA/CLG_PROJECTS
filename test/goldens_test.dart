import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:four_screens_app/theme/app_theme.dart';
import 'package:four_screens_app/screens/home_screen.dart';
import 'package:four_screens_app/screens/explore_screen.dart';
import 'package:four_screens_app/screens/favorites_screen.dart';
import 'package:four_screens_app/screens/profile_screen.dart';

Future<void> _setGoldenSize(WidgetTester tester,
    {Size logicalSize = const Size(800, 600), double devicePixelRatio = 1.0}) async {
  tester.binding.window.devicePixelRatioTestValue = devicePixelRatio;
  tester.binding.window.physicalSizeTestValue =
      Size(logicalSize.width * devicePixelRatio, logicalSize.height * devicePixelRatio);
  addTearDown(() {
    tester.binding.window.clearPhysicalSizeTestValue();
    tester.binding.window.clearDevicePixelRatioTestValue();
  });
}

void main() {
  testWidgets('Home screen golden', (tester) async {
    await _setGoldenSize(tester);
    await tester.pumpWidget(MaterialApp(theme: AppTheme.light(), home: const HomeScreen()));
    await tester.pumpAndSettle();
    await expectLater(find.byType(MaterialApp), matchesGoldenFile('goldens/home.png'));
  });

  testWidgets('Explore screen golden', (tester) async {
    await _setGoldenSize(tester);
    await tester.pumpWidget(MaterialApp(theme: AppTheme.light(), home: const ExploreScreen()));
    await tester.pumpAndSettle();
    await expectLater(find.byType(MaterialApp), matchesGoldenFile('goldens/explore.png'));
  });

  testWidgets('Favorites screen golden', (tester) async {
    await _setGoldenSize(tester);
    await tester.pumpWidget(MaterialApp(theme: AppTheme.light(), home: const FavoritesScreen()));
    await tester.pumpAndSettle();
    await expectLater(find.byType(MaterialApp), matchesGoldenFile('goldens/favorites.png'));
  });

  testWidgets('Profile screen golden', (tester) async {
    await _setGoldenSize(tester);
    await tester.pumpWidget(MaterialApp(theme: AppTheme.light(), home: const ProfileScreen()));
    await tester.pumpAndSettle();
    await expectLater(find.byType(MaterialApp), matchesGoldenFile('goldens/profile.png'));
  });
}

