export default function dashboardLayout({ children }: { children: React.ReactNode }) {
  return (
    <div>
      <header className="border-b border-green-500">Dashboard Layout</header>

      {children}
    </div>
  );
}
